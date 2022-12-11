#pragma once
#include "airports.h"
#include "utils.h"

#include <string>
#include <vector>

using namespace std;


struct Node{
    string airport;
    vector<Node*> neighbors;
    double latitude;
    double longitude;
    double distance = 100000;
};
class Graph{
private:
    vector<Node*> airport_nodes_;
    vector<vector<int>> adjacency_matrix_;
    void insertAllVertices(unordered_map<string,pair<double, double>> airports);
    void insertAllEdges(map<pair<string,string>,double> route);
    
    map<Node*, Node*> bfsHelper(Node* source);

    Node * graphFind(vector<Node*> airport_node, string dest);
    static bool pageRankComparator(Node* a, Node* b);
    double calculateDistance(Node* airport1,Node* airport2) const;
    double deg2rad(double deg) const;
    void clearDistance();
public:
    Graph();
    Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route);

    ~Graph();
    vector<string> bfsFindPath(map<Node*, Node*> m, Node* source, Node* dest);
    vector<string> BFS(string start, string end);
    vector<string> top_airports(int count);
    pair<vector<Node*>,double> dijFind(string start_airport,string dest_airport);
    vector<Node*> getAirportNode(); // for testing
    Node* getNode(string airportName); 
    // double getNodeLatitude(Node* ap);
    // double getNodeLongitude(Node *ap);
};