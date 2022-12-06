#pragma once
#include "airports.h"
#include "utils.h"

#include <string>
#include <vector>

using namespace std;


struct Node{
    string airport;
    vector<Node*> neighbors;
};
class Graph{
private:
    vector<Node*> airport_nodes_;
    vector<vector<int>> adjacency_matrix_;
    void insertAllVertices(unordered_map<string,pair<double, double>> airports);
    void insertAllEdges(map<pair<string,string>,double> route);
    Node* getNode(string airportName); 
    map<Node*, Node*> bfsHelper(Node* source);
    vector<string> bfsFindPath(map<Node*, Node*> m, Node* source, Node* dest);
    Node * graphFind(vector<Node*> airport_node, string dest);
    static bool pageRankComparator(Node* a, Node* b);
public:
    Graph();
    Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route);

    ~Graph();
    
    vector<string> BFS(string start, string end);
    vector<string> top_airports(int count);

    vector<Node*> getAirportNode(); // for testing
};