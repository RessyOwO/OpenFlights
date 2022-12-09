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

typedef std::vector<std::vector<std::string> > V2D; 

class Airports {
private:
    // key is the airport id, value is latitude and longitude.
    unordered_map<string,pair<double, double>> airports;



    double deg2rad(double deg) const;
public:
    Airports(const string& filename);

    Airports();

    void addAirports(string IATA,double lat,double lon);

    double calculateDistance(string airport1,string airport2) const;

    double getLatitude(string airport) const;

    double getLongitude(string airport) const;

    int getAirportNum();

    bool find(string airport);

    unordered_map<string,pair<double, double>> getAirportsMap();

    void readString(string &start_airport,string &dest_airport);
};

class Routes{
private:
    //key is <IATA1,IATA2>,distance
    map<pair<string,string>,double> route;
public:
    Routes(Airports airport,const string& filename);

    void insert(string airport1,string airport2,double distance);

    double getDistance(string airport1,string airport2);

    bool find(string airport1,string airport2);

    int getRouteNum();

    map<pair<string,string>,double> getRoute();
};