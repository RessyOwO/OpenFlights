#include <iostream>
#include <string>
#include <vector>
#include "airports.cpp"
using namespace std;
int main() {
  std::cout << "1234" << std::endl;
  string test = "today,all,good";
  char c = ',';
  vector<string> test1 = split(test, c);
  //cout << test1.size() << endl;
  for (auto& x : test1) {
    cout << x << endl;
  }
  return 0;
}