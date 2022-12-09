#include "airports.h"
#include "utils.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
 
/**
 * @brief This function calculates the distance between two airports
 * 
 * @param airport1 
 * @param airport2 
 * @return Distance between the two airports
 */
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

/**
 * @brief Add a airport manually
 * 
 * @param IATA IATA code
 * @param lat latitude
 * @param lon longitude
 */
void Airports::addAirports(string IATA,double lat,double lon){
    pair<double, double> l(lat,lon);
    airports.insert({IATA,l});
}

/**
 * @brief Function that returns the map for airports
 * 
 * @return unordered_map<IATA,pair<latitude,longitude>> 
 */
unordered_map<string,pair<double, double>> Airports::getAirportsMap() {
    return airports;
}

/**
 * @brief Construct a new empty Airports:: Airports object
 * 
 */
Airports::Airports(){}

/**
 * @brief Returns the latitude of the airport
 * 
 * @param airport 
 * @return distance
 */
double Airports::getLatitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"ERROR"<<endl;
        return 0;
    }
    return it->second.first;
}

/**
 * @brief Returns the longitude
 * 
 * @param airport 
 * @return longitude
 */
double Airports::getLongitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        return 0;
    }
    return it->second.second;

}

/**
*@brief This function turns degrees into radians
*
*@param degrees
*@return radians
*/
double Airports::deg2rad(double deg) const{
    return deg*(M_PI/180);
}

/**
 * @brief Construct a new Airports:: Airports object
 * 
 * @param filename file that contains all airports
 */
Airports::Airports(const string& filename){
    V2D airportVec = file_to_V2D(filename);
    for(vector<string> it : airportVec){
        addAirports(it[1],stod(it[2]),stod(it[3]));
    }
}

/**
 * @brief Construct a new Routes:: Routes object
 * 
 * @param airport the airport class associated with the routes
 * @param filename file that contains all the routes
 */
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
/**
 * @brief This function inserts two airports and their distances into the route
 * 
 * @param airport1 
 * @param airport2 
 * @param distance 
 */
void Routes::insert(string airport1,string airport2,double distance){
    pair<string,string> p(airport1,airport2);
    route.insert({p,distance});
}


/**
 * @brief This function gets the distance between two airports
 * 
 * @param airport1 
 * @param airport2 
 * @return distance (-1 if it does not exist)
 */
double Routes::getDistance(string airport1,string airport2){
    pair<string,string> p(airport1,airport2);
    auto it = route.find(p);
    if(it == route.end())
        return -1;
    return it->second;
}

/**
 * @brief This function true returns if a route bewteen two distance exists
 * 
 * @param airport1 
 * @param airport2 
 * @return true route exist
 * @return false route does not exist
 */
bool Routes::find(string airport1,string airport2){
    pair<string,string> p(airport1,airport2);
    auto it = route.find(p);
    if(it == route.end())
        return false;
    return true;
}

/**
 * @brief This function gets the number of airports
 * 
 * @return number of airports
 */
int Airports::getAirportNum(){
    return airports.size();
}

/**
 * @brief This function gets the number of routes
 * 
 * @return number of routes
 */
int Routes::getRouteNum(){
    return route.size();
}

/**
 * @brief This function checks if a airport exists in the current class
 * 
 * @param airport 
 * @return true if the airport exists
 * @return false if the airport does not exist
 */
bool Airports::find(string airport){
    if(airports.find(airport) != airports.end())
        return true;
    return false;
}

/**
 * @brief Returns the map with the routes
 * 
 * @return map<pair<string,string>,double> 
 */
map<pair<string,string>,double> Routes::getRoute() {
    return route;
}