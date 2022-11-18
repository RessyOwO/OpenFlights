#pragma once 
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using std::vector;
using std::map;
using std::unordered_map;
using std::string;
using std::pair;

class AirPorts {
public:
    AirPorts(const std::string& filename);

    double getDistance(string airport1,string airport2) const;
private:
    // key is the airport id, value is latitude and longitude.
    unordered_map<string,pair<double, double>> airports;

    double latitude(string airport) const;

    double longitude(string airport) const;
};

