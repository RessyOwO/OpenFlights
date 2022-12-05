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
public:
    Graph();
    Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route);

    ~Graph();
    // void insertVertex(int v, Node* airport);
    void insertAllVertices(unordered_map<string,pair<double, double>> airports);
    void insertAllEdges(map<pair<string,string>,double> route);
    Node * graphFind(vector<Node*> airport_node, string dest);

    vector<Node*> getAirportNode();
    vector<string> BFS(Node* source, Node* dest);
    map<Node*, Node*> bfsHelper(Node* source);
    vector<string> bfsFindPath(map<Node*, Node*> m, Node* source, Node* dest);

};