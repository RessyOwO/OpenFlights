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

class Airports {
public:
    Airports(const std::string& filename);

    Airports();

    void addAirports(string IATA,double lat,double lon);

    double calculateDistance(string airport1,string airport2) const;
protected:
    // key is the airport id, value is latitude and longitude.
    unordered_map<string,pair<double, double>> airports;

    double getLatitude(string airport) const;

    double getLongitude(string airport) const;

    double deg2rad(double deg) const;
};

class Airports::Routes{
private:
    map<pair<string,string>,double> route;
public:
    Routes();

    Routes(string filename);

    void insert(string airport1,string airport2,double distance);

    double getDistance(string airport1,string airport2);

    bool find(string airport1,string airport2);
};