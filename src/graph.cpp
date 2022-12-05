
#include "graph.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


Graph::Graph(){

}


Graph::Graph(unordered_map<string,pair<double, double>> airports, map<pair<string,string>,double> route) {
    insertAllVertices(airports);
    insertAllEdges(route);

}
Graph::~Graph() {
    airport_nodes_.clear();
    airport_nodes_.shrink_to_fit();
}

vector<Node*> Graph::getAirportNode() {
    return airport_nodes_;
}

void Graph::insertAllVertices(unordered_map<string,pair<double, double>> airports) {
    for (const auto & k : airports) {
        Node * n = new Node();
        n->airport = k.first;
        n->neighbors = vector<Node*>();
        airport_nodes_.push_back(n); 
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
        auto key = graphFind(airport_nodes_, r.first.first);
        auto val = graphFind(airport_nodes_, r.first.second);
        key->neighbors.push_back(val);
    }

}


map<Node*, Node*> Graph::bfsHelper(Node* source) {
    map<Node*, bool> visited;
    for (size_t i = 0; i < airport_nodes_.size(); i++) {
        visited.insert(pair<Node*, bool>(airport_nodes_[i], false));
    }
    map<Node*, Node*> result;

    queue<Node*> queue;
    queue.push(source);
    Node* curr = source;
    visited.at(source) = true;
    while (!queue.empty()) {
        curr = queue.front();
        queue.pop();
        for (auto & it : curr->neighbors) {
            if (visited.at(it) == false) {
                queue.push(it);  
                visited.at(it) = true;
                result[it] = curr;
            }
        }
    }

    return result;

}

vector<string> Graph::bfsFindPath(map<Node*, Node*> m, Node* source, Node* dest) {
    vector<string> path;
    for (auto & it = dest; it != NULL; it = m[it]) {
        path.push_back(it->airport);
    }
    reverse(path.begin(), path.end());
    if (path.at(0) == source->airport) return path;
    return vector<string>();
}

vector<string> Graph::BFS(string start, string end) {
    Node * source = getNode(start);
    Node * dest = getNode(end);
    return bfsFindPath(bfsHelper(source), source, dest);
}

Node* Graph::getNode(string airportName) {
    for (size_t i = 0; i < airport_nodes_.size(); i++) {
        if (airport_nodes_[i]->airport == airportName) {
            return airport_nodes_[i];
        }
    }
    return NULL;
}

bool Graph::pageRankComparator(Node* a, Node* b) {
    return a->neighbors.size() > b->neighbors.size();
}

// returns top "count" airports
// PageRank algo
vector<string> Graph::top_airports(int count) {
    vector<string> to_return;
    sort(airport_nodes_.begin(), airport_nodes_.end(), pageRankComparator);
    int bound = count;
    if ((int)airport_nodes_.size() < bound) bound = airport_nodes_.size();
    for (size_t i = 0; i < (size_t) bound; i++) {
        to_return.push_back(airport_nodes_[i]->airport);
    }
    return to_return;
}