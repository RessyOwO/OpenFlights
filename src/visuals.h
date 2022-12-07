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
    void MarkTop100();
    void MarkRoute(string start, string end);
    void Write(const string& filenameA);
    private:
    Graph* graph;
    Airports* airport;
    Routes* route;
    PNG* png; 
};