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

    Airports(string IATA,double lat,double lon);

    double getDistance(string airport1,string airport2) const;
private:
    // key is the airport id, value is latitude and longitude.
    unordered_map<string,pair<double, double>> airports;

    double getLatitude(string airport) const;

    double getLongitude(string airport) const;

    double deg2rad(double deg) const;
};

