# CS225 Final Project: OpenFlights Report
##### By: Relena Li, Haosen Yao, Jin Jiang

In this project, we want to explore the [OpenFlights](https://openflights.org/data.html) dataset to gain insights of how one optimizes their traveling path.
We want to visualize the shortest path (stop wise and distance wise) between two places.

P.S. We ignored all the airports that does not have IATA codes

A summary of our project and its results can be found in this presentation.

[Prsentation slides](https://docs.google.com/presentation/d/1T_b8ztMlkADHwnpig6dSY01ThUqpgwkUn1H38vdvA6Y/edit?usp=sharing)

[Presentation video]()

We decided to use BFS to check if there exists a path between two places and obtain the path with fewest stops.
We also want to find the shortest path (distance wise) using Dijkstra’s Algorithm. 
Finally, we want to visualize the shortest path between two places and mark relatively important places using the Page Rank Algorithm.

We started our project by gathering data and parsing data into format that we can use. We obtained airports.dat and routes.dat from [OpenFlights](https://openflights.org/data.html). We then processed the data using python and stored in new_airports.txt and new_routes.txt. Only the useful parts of the data were taken into account. For airports, we discarded data that are missing one or all of `[Airport ID] [Name] [IATA] [Latitude] [Longitude]`. For air routes, we discarded data that are missing one of or all of `[Source airport ID] [Destination airport ID]`.

For data storage, we created two classes, `airports` and `routes` to store the data. For airports, we created an unordered map to store the `[Airport IATA]` and `[coordinates]`. We created a function to convert `[Latitude]` and `[Longitude]` into a pair <x,y> that works on a PNG. For routes, we created an unordered map to store the `[Source airport IATA]` and the `[Desination airport IATA]`. For available routes, we created a function to draw out the line for routes.

For our graph construction, we established a struct `Node` containing `[Airport IATA]`, `neighbor` vector containing all neighboring Nodes, `latitude`, and `longitude` of the airport. Testing on small sample data sets is done to check the correctness of our graph.

The first algorithm we implemented was Breadth-first search (BFS) for checking if a path exists / finding a path with fewest stops. It takes in two `[Airport IATA]` as parameters, and if the path exists between two airports, it returns a path represented by a `vector<string>` consisting `[Airport IATA]`. If the path does not exist, it returns a `vector<string>` of size 0. Testing was done on small sets of example data to confirm accuracy. The running time of our BFS find shortest path is `O(V + E)` where V is the number of vertices and E is the total number of edges, which is relatively fast.

The second algorithm we implemented was Dijkstra's Algorithm. We want to use Dijkstra's Algorithm to find the path with the shortest distance between two graph nodes. It takes in two `[Airport IATA]` as parameters, and if the path exists between two airports, it returns a path represented by a `pair<vector<Node*>,double>` consisting of a vector of airport Node pointers and the total distance. If the path does not exist, it returns a pair where 'vector<Node*>`is empty and distance is -1. Testing was done on small sets of example data to confirm accuracy. Dijkstra's shortest path algorithm's running time is `O(ElogV)` where V is the number of vertices and E is the total number of edges.

The third algorithm we implemented was PageRank Algorithm. We want to use PageRank algorithm to find the most important airports. The importance of airport is decided based on the number of its neighbors. Since it is impossible to show all airports on the map, we want to show the most important ones using PageRank Algorithm. It takes in a integer and returns a `vector<string>` consisting top `int` number of `[Airport IATA]`. Based on our implementation of the graph structure, all we have to do is to sort `airport_nodes_` by size of `neighbors`, so the running time is `O(nlog(n))`. Testing of PageRank Algorithm was done by running the algorithm on full set of data. It took about 5 seconds to return the result we want, which is acceptable.

In this project, we explored the OpenFlights dataset and gained insights of how one optimizes their traveling path. Our BFS algorithm returns a path with shortest stops when two IATA codes are inputted. However, this might not be the most efficient path distance and time wise. Our Dijkstra's algorithm returns the a path with shortest distance of traveling when starting airport and end airport IATA codes are inputted. Our PageRank algorithm returns the most important airports with the most neighbors for one's reference. We also successfully visualized the shortest path between two places.

Overall, we have an 100% completion on our goals, and this project reinforced concepts and data structures that we learned throughout the semester.
