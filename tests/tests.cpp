#include <catch2/catch_test_macros.hpp>

#include<iostream>
#include "airports.h"
#include "graph.h"
using namespace std;

TEST_CASE("A test of catch2", "[weight=1][part=1]") {
  	REQUIRE(1 == 1);
}

TEST_CASE("getDistance working", "[weight=1][part=1]") {
  	Airports airport;
  	airport.addAirports("1",0,0);
  	airport.addAirports("2",30,0);
  	double distance = airport.calculateDistance("1","2");
  	REQUIRE(distance > 0);
}
TEST_CASE("Airports constructor working", "[weight=1][part=1]") {
  	Airports airport("../tests/airport_test1.txt");

  	REQUIRE(airport.calculateDistance("AAA","BBB") == airport.calculateDistance("AAA","DDD"));
  	REQUIRE(airport.calculateDistance("AAA","CCC") == airport.calculateDistance("AAA","EEE"));
}

TEST_CASE("Routes constructor working", "[weight=1][part=1]") {
  	Airports airport("../tests/airport_test1.txt");
	Routes route(airport,"../tests/route_test1.txt");

  	REQUIRE(route.getDistance("AAA","BBB") == route.getDistance("AAA","DDD"));
  	REQUIRE(route.getDistance("AAA","CCC") == route.getDistance("AAA","EEE"));
	REQUIRE(route.getDistance("BBB","DDD") == route.getDistance("CCC","EEE"));
}

TEST_CASE("Routes find/insert working", "[weight=1][part=1]") {
  	Airports airport("../tests/airport_test1.txt");
	Routes route(airport,"../tests/route_test1.txt");

  	REQUIRE(!route.find("BBB","CCC"));
	route.insert("BBB","CCC",airport.calculateDistance("BBB","CCC"));
  	REQUIRE(route.find("BBB","CCC"));
}

TEST_CASE("Airports/Routes full doc working", "[weight=1][part=1]") {
	Airports airport("../data/new_airports.txt");
	Routes route(airport,"../data/new_routes.txt");
	CHECK(airport.getAirportNum() == 6072);
  	CHECK(route.getRouteNum() == 37042);
}

TEST_CASE("Graph constructor working", "[weight=1][part=1]") {
	Airports airport("../tests/airport_test1.txt");
	Routes route(airport,"../tests/route_test1.txt");
	Graph graph(airport.getAirportsMap(), route.getRoute());
	CHECK(graph.getAirportNode().size() == 5);
	CHECK(graph.getAirportNode()[0]->airport == "EEE");
	CHECK(graph.getAirportNode()[1]->airport == "CCC");
	CHECK(graph.getAirportNode()[2]->airport == "DDD");
	CHECK(graph.getAirportNode()[3]->airport == "BBB");
	CHECK(graph.getAirportNode()[4]->airport == "AAA");
	// cout << graph.getAirportNode()[1]->neighbors[0]->airport << endl;
	// cout << graph.getAirportNode()[1]->neighbors[0]->neighbors.size() << endl;
	// cout << graph.getAirportNode()[2]->airport << endl;
	// cout << graph.getAirportNode()[3]->airport << endl;
	// cout << graph.getAirportNode()[4]->airport << endl;
  	CHECK(graph.getAirportNode()[0]->neighbors.size() == 0);
	CHECK(graph.getAirportNode()[1]->neighbors.size() == 1);
	CHECK(graph.getAirportNode()[2]->neighbors.size() == 0);
	CHECK(graph.getAirportNode()[3]->neighbors.size() == 1);
	CHECK(graph.getAirportNode()[4]->neighbors.size() == 4);
}

TEST_CASE("BFS working", "[weight=1][part=1]") {
	Airports airport("../tests/airport_test1.txt");
	Routes route(airport,"../tests/route_test2.txt");
	Graph graph(airport.getAirportsMap(), route.getRoute());

	vector<string> path = graph.BFS("AAA", "EEE");
	CHECK(path.size() == 3);
	CHECK(path[0] == "AAA");
	CHECK(path[1] == "CCC");
	CHECK(path[2] == "EEE");
	vector<string> path2 = graph.BFS("BBB", "EEE");
	CHECK(path2.size() == 3);
	CHECK(path2[0] == "BBB");
	CHECK(path2[1] == "DDD");
	CHECK(path2[2] == "EEE");

	Airports airport2("../tests/airport_test1.txt");
	Routes route2(airport,"../tests/route_test1.txt");
	Graph graph2(airport2.getAirportsMap(), route2.getRoute());

	vector<string> p1 = graph2.BFS("AAA", "EEE");
	CHECK(p1.size() == 2);
	CHECK(p1[0] == "AAA");
	CHECK(p1[1] == "EEE");
	vector<string> p2 = graph2.BFS("BBB", "EEE");
	CHECK(p2.size() == 0);
	
}