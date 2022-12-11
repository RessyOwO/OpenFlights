#pragma once
#include "airports.h"
#include "graph.h"
#include "cs225/PNG.h"
using cs225::PNG;
class Visual {
    public:
    Visual() = default;
    Visual(const string& filenameA, const string& filenameR, const string& filenameV);
    void MarkAirports();
    void MarkTopX(int x);
    void MarkRoute(string start, string end);
    void Write(const string& filenameA);
    pair<double,double> MarkStartAirport(string ap);
    pair<double,double> MarkEndAirport(string ap);
    private:
    Graph* graph;
    Airports* airport;
    Routes* route;
    PNG* png; 
};