#include <catch2/catch_test_macros.hpp>

#include "airports.h"
#include "graph.h"


TEST_CASE("A test of catch2", "[weight=1][part=1]") {
  REQUIRE(1 == 1);
}

TEST_CASE("getDistance working", "[weight=1][part=1]") {
  Airports airport;
  airport.addAirports("1",0,0);
  airport.addAirports("2",30,0);
  double distance = airport.getDistance("1","2");
  REQUIRE(distance > 0);
}