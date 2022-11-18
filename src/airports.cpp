#include "airports.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

//This function is not finished
double AirPorts::getDistance(string airport1,string airport2) const{
    return 0;
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

double AirPorts::latitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"The airport ["<<airport<<"] does not exist"<<endl;
        return 0;
    }
    return it->second.first;
}

double AirPorts::longitude(string airport) const{
    auto it = airports.find(airport);
    if(it == airports.end()){
        cout<<"The airport ["<<airport<<"] does not exist"<<endl;
        return 0;
    }
    return it->second.second;

}