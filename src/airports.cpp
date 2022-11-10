#include "airports.h"
#include <fstream>
using namespace std;
vector<string> split(string str, char del) {
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != del) {
            temp += str[i];
        } else {
            ans.push_back(temp);
            temp = "";
        }
    }
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