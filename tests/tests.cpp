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
	Routes route2(airport2,"../tests/route_test1.txt");
	Graph graph2(airport2.getAirportsMap(), route2.getRoute());

	vector<string> p1 = graph2.BFS("AAA", "EEE");
	CHECK(p1.size() == 2);
	CHECK(p1[0] == "AAA");
	CHECK(p1[1] == "EEE");
	vector<string> p2 = graph2.BFS("BBB", "EEE");
	CHECK(p2.size() == 0);

}

TEST_CASE("PageRank working", "[weight=1][part=1]") {
	Airports airport("../tests/airport_test1.txt");
	Routes route(airport,"../tests/route_test1.txt");
	Graph graph(airport.getAirportsMap(), route.getRoute());

	vector<string> top1 = graph.top_airports(1);
	CHECK(top1.size() == 1);
	CHECK(top1[0] == "AAA");

	Airports airport2("../tests/airport_test1.txt");
	Routes route2(airport2,"../tests/route_test2.txt");
	Graph graph2(airport2.getAirportsMap(), route2.getRoute());
	vector<string> top22 = graph2.top_airports(2);
	CHECK(top22.size() == 2);
	CHECK(top22[0] == "AAA");

	Airports airport3("../data/new_airports.txt");
	Routes route3(airport3,"../data/new_routes.txt");
	Graph graph3(airport3.getAirportsMap(), route3.getRoute());
	vector<Node*> airports = graph3.getAirportNode();
	CHECK(airports.size() == 6072);

	// vector<string> r = graph3.BFS("AER", "KZN");
	// cout << r.size() << endl;

	vector<string> top310= graph3.top_airports(10);
	CHECK(top310.size() == 10);
	CHECK(top310[0] == "FRA");
	CHECK(top310[1] == "CDG");
	CHECK(top310[2] == "AMS");
	CHECK(top310[3] == "IST");
	CHECK(top310[4] == "ATL");
	CHECK(top310[5] == "ORD");
	CHECK(top310[6] == "PEK");
	CHECK(top310[7] == "MUC");
	CHECK(top310[8] == "DME");
	CHECK(top310[9] == "DFW");
	
}

TEST_CASE("Dijkstra_simple", "[weight=1][part=2]"){
	Airports airport("../tests/airport_testA.txt");
	Routes route(airport,"../tests/route_testA.txt");
	Graph graph(airport.getAirportsMap(), route.getRoute());

	SECTION("A to B"){
		pair<vector<Node*>,double> ans = graph.dijFind("A","B");
		vector<string> sol;
		for(Node* it : ans.first){
			sol.push_back(it->airport);
		}
		CHECK(sol[0] == "A");
		CHECK(sol[1] == "B");
		CHECK(sol.size() == 2);
	}
	SECTION("A to C"){
		pair<vector<Node*>,double> ans = graph.dijFind("A","C");
		vector<string> sol;
		for(Node* it : ans.first){
			sol.push_back(it->airport);
		}
		CHECK(sol[0] == "A");
		CHECK(sol[1] == "C");
		CHECK(sol.size() == 2);
	}
	SECTION("B to C"){
		pair<vector<Node*>,double> ans = graph.dijFind("B","C");
		vector<string> sol;
		for(Node* it : ans.first){
			sol.push_back(it->airport);
		}
		CHECK(sol[0] == "B");
		CHECK(sol[1] == "C");
		CHECK(sol.size() == 2);
	}
	SECTION("A to D"){
		pair<vector<Node*>,double> ans = graph.dijFind("A","D");
		vector<string> sol;
		for(Node* it : ans.first){
			sol.push_back(it->airport);
		}
		CHECK(sol[0] == "A");
		CHECK(sol[1] == "C");
		CHECK(sol[2] == "D");
		CHECK(sol.size() == 3);
	}

	SECTION("E to F"){
		pair<vector<Node*>,double> ans = graph.dijFind("E","F");
		vector<string> sol;
		for(Node* it : ans.first){
			sol.push_back(it->airport);
		}
		CHECK(sol[0] == "E");
		CHECK(sol[1] == "F");
		CHECK(sol.size() == 2);
	}
}