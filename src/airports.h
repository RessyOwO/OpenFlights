#pragma once 
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using std::vector;
using std::map;
using std::unordered_map;
class AirPorts {
    public:
        AirPorts(const std::string& filename);


    private:
        // key is the airport id, value is latitude and longitude.
        std::unordered_map<std::string, std::pair<double, double>> airports;




};

