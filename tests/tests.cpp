#include <catch2/catch_test_macros.hpp>

#include "airports.h"
#include "routes.h"


TEST_CASE("A test of catch2", "[weight=1][part=1]") {
  REQUIRE(1 == 1);
}

TEST_CASE("getDistance working", "[weight=1][part=1]") {
  AirPorts airport;
  airport.addAirPorts("1",0,0);
  airport.addAirPorts("2",30,0);
  double distance = airport.getDistance("1","2");
  REQUIRE(distance > 0);
}