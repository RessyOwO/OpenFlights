#include "airports.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

//This function calculates the distance between two airports
//@param 2 airports to be calculated
//@return the distance(km)
double Airports::calculateDistance(string airport1,string airport2) const{
    int R = 6371;
    double lat1 = getLatitude(airport1);
    double lat2 = getLatitude(airport2);
    double long1 = getLongitude(airport1);
    double long2 = getLongitude(airport2);
    double dLat = deg2rad(lat1 - lat2);
    double dLong = deg2rad(long1 - long2);
    double a = cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLong/2) * sin(dLong/2);
    a = a + sin(dLat/2) * sin(dLat/2);
    double c = 2 * atan(sqrt(a)/sqrt(1-a));
    return R*c;
}

//Helper function for catch2
void Airports::addAirports(string IATA,double lat,double lon){
    pair<double, double> l(lat,lon);
    airports.insert({IATA,l});
}

//Helper constructor for catch2
Airports::Airports(){}

//This function returns the latitude
//@param airport
//@return the latitude of the airport
double Airports::getLatitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"ERROR"<<endl;
        return 0;
    }
    return it->second.first;
}

//This function returns the longitude
//@param airport
//@return the longitude of the airport
double Airports::getLongitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        return 0;
    }
    return it->second.second;

}

//This function turns degrees into radians
//@param degrees
//@return radians
double Airports::deg2rad(double deg) const{
    return deg*(M_PI/180);
}

//The constructor for Airports class
//@param the file which contains all airports
Airports::Airports(const string& filename){
    V2D airportVec = file_to_V2D(filename);
    for(vector<string> it : airportVec){
        addAirports(it[1],stod(it[2]),stod(it[3]));
    }
}

//The constructor for Routes class
//@param the file which contains all routes
Routes::Routes(Airports airport,const string& filename){
    V2D routeVec = file_to_V2D(filename);
    for(vector<string> it : routeVec){
        if(airport.find(it[1]) && airport.find(it[2])){
            double distance = airport.calculateDistance(it[1],it[2]);
            insert(it[1],it[2],distance);
        }
    }
}

//This function inserts two airports and their distances into the route
//@airports' IATA and its distances
//@None
void Routes::insert(string airport1,string airport2,double distance){
    pair<string,string> p(airport1,airport2);
    route.insert({p,distance});
}

//This function gets the distance between two airports
//@param airports' IATA
//@return distance if existed, -1 if not
double Routes::getDistance(string airport1,string airport2){
    pair<string,string> p(airport1,airport2);
    auto it = route.find(p);
    if(it == route.end())
        return -1;
    return it->second;
}

//This function returns if a route bewteen two distance exists
//@param airports' IATA
//@return true if exists,false if not
bool Routes::find(string airport1,string airport2){
    pair<string,string> p(airport1,airport2);
    auto it = route.find(p);
    if(it == route.end())
        return false;
    return true;
}

//This function gets the number of airports
//@param none
//@return number of airports
int Airports::getAirportNum(){
    return airports.size();
}

//This function gets the number of routes
//@param none
//@return number of routes
int Routes::getRouteNum(){
    return route.size();
}

//This function checks if a airport exists in the current class
//@param airport's IATA
//@return true if exists, false if not
bool Airports::find(string airport){
    if(airports.find(airport) != airports.end())
        return true;
    return false;
}