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