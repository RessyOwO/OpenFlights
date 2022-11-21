#pragma once

#include<vector>


struct Node{
    string IATA;
    vector<Node*> neighbor;
};
class Graph{
private:
    vector<Node*> airport_node;

public:
    Graph();

    ~Graph();
};