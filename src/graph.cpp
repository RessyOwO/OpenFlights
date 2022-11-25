
#include "graph.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


Graph::Graph(){

}


Graph::Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route) {
    insertAllVertices(airports);
    insertAllEdges(route);

}
Graph::~Graph() {
    airport_node.clear();
    airport_node.shrink_to_fit();
}

vector<Node*> Graph::getAirportNode() {
    return airport_node;
}
// void Graph::insertVertex(int v, Node* airport) {
//     airport_node[v] = airport;
// }

void Graph::insertAllVertices(unordered_map<string,pair<double, double>> airports) {
    for (const auto & k : airports) {
        Node * n = new Node();
        n->airport = k.first;
        n->neighbors = vector<Node*>();
        airport_node.push_back(n); 
    } 
}

Node * Graph::graphFind(vector<Node*> airport_node, string dest) {
    for (size_t i = 0; i < airport_node.size(); i++) {
        if (airport_node[i]->airport == dest) {
            return airport_node[i];
        }
    }
    return NULL;

}

void Graph::insertAllEdges(map<pair<string,string>,double> route) {
    for (const auto & r : route) {
        auto key = graphFind(airport_node, r.first.first);
        auto val = graphFind(airport_node, r.first.second);
        key->neighbors.push_back(val);
    }

}

