#include <iostream>
#include <string>
#include <vector>
#include "airports.h"
#include "graph.h"
#include "visuals.h"
using namespace std;
int main() {

  	cout<<"Make sure that all the '.txt'files are in LF format!"<<endl;
  	cout<<"Reading from 'new_airports.txt'"<<endl;
	Airports airport("../data/new_airports.txt");
  	cout<<"Reading from 'new_routes.txt'"<<endl;
  	Routes route(airport,"../data/new_routes.txt");
	cout<<"Creating the graph"<<endl;
	Graph graph(airport.getAirportsMap(), route.getRoute());
  	cout<<"Complete!"<<endl;
  	cout<<"Airports: "<<airport.getAirportNum()<<" Routes: "<<route.getRouteNum()<<endl;
  	while(true){
		int a;
		cout<<"Type 1 for BST, 2 for Dijkstra, 3 for pagerank, 0 to quit"<<endl;
  		cout<<"Waiting for input: ";
  		cin>>a;
		string start_airport;
		string dest_airport;
		if(a == 1){
			airport.readString(start_airport,dest_airport);
			cout<<"Airports read, calculating path with least stops"<<endl;
			vector<string> sol = graph.BFS(start_airport,dest_airport);
			if(sol.empty()){
				cout<<"This path does not exist"<<endl;
			}else{
				cout<<"The path is: ";
				for(auto it : sol){
						cout<<it<<" ";
				}
				cout<<endl;
			}
		}else if(a == 2){
			airport.readString(start_airport,dest_airport);
			cout<<"Airports read, calculating shortest path"<<endl;
			auto ans = graph.dijFind(start_airport,dest_airport);
			if(ans.second == -1){
				cout<<"This path does not exist"<<endl;
			}else{
				cout<<"The path is: ";
				for(auto it : ans.first){
					cout<<it->airport<<" ";
				}
				cout<<endl;
				cout<<"The total distance traveled is: "<<ans.second<<endl;
			}
		}else if(a == 3){
			int count;
			cout<<"Type in count: ";
			cin>>count;
			cout<<"Airports read, calculating pageRank"<<endl;
			vector<string> result = graph.top_airports(count);
			cout<<"The airport(s) with the "<<count<<" th most of airports is: "<<endl;
			for(auto it : result){
					cout<<it<<" ";
				}
			cout<<endl;
		}else if(a == 0){
			cout<<"Exiting..."<<endl;
			return 0;
		}else{
			cout<<"Invalid"<<endl;
		}
	}
  	return 0;
}