#include "airports.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

//This function is not finished
double AirPorts::getDistance(string airport1,string airport2) const{
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

AirPorts::AirPorts(string IATA,double lat,double lon){
    pair<double, double>(lat,lon);
}

vector<string> split(string str, char del) {
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != del) {
            temp += str[i];
            //std::cout << temp << std::endl;
        } else {
            ans.push_back(temp);
            temp = "";
        }
    }
    //td::cout << temp << std::endl;
    ans.push_back(temp);
    return ans;

}
AirPorts::AirPorts(const std::string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
      while (getline(wordsFile, word)) {
        string s = word;
        //sort(s.begin(), s.end());
        //dict[s].push_back(word);
      }
    }
}

//This function returns the latitude
//@param airport
//@return the latitude of the airport
double AirPorts::getLatitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"The airport ["<<airport<<"] does not exist"<<endl;
        return 0;
    }
    return it->second.first;
}

//This function returns the longitude
//@param airport
//@return the longitude of the airport
double AirPorts::getLongitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"The airport ["<<airport<<"] does not exist"<<endl;
        return 0;
    }
    return it->second.second;

}

//This function turns degrees into radians
//@param degrees
//@return radians
double AirPorts::deg2rad(double deg) const{
    return deg*(M_PI/180);
}