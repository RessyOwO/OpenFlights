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
    vector<Node*> airport_node;
public:
    Graph();
    Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route);

    ~Graph();
    // void insertVertex(int v, Node* airport);
    void insertAllVertices(unordered_map<string,pair<double, double>> airports);
    void insertAllEdges(map<pair<string,string>,double> route);
    Node * graphFind(vector<Node*> airport_node, string dest);
};