#include <iostream>
#include <string>
#include <vector>
#include "airports.h"
#include "graph.h"
#include "visuals.h"
using namespace std;
int main() {
	//Airports airport("../data/new_airports.txt");
	//Routes route(airport,"../data/new_routes.txt");

    Visual* v = new Visual("../data/new_airports.txt", "../data/new_routes.txt", "../data/map.png");
    v->MarkRoute("AER", "KZN");
    v->Write("../data/out.png");
	
  	return 0;
}