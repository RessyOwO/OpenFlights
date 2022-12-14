# CS225 Final Project: OpenFlights
##### By: Relena Li, Haosen Yao, Jin Jiang

## **Introduction:**

In this project, we want to explore the [OpenFlights](https://openflights.org/data.html) dataset to gain insights of how one optimizes their traveling path.
We want to visualize the shortest path (stop wise and distance wise) between two places.

 P.S. We ignored all the airports that does not have IATA codes

A summary of our project and its results can be found in this presentation.

[Prsentation slides](https://docs.google.com/presentation/d/1T_b8ztMlkADHwnpig6dSY01ThUqpgwkUn1H38vdvA6Y/edit?usp=sharing)

[Presentation video](https://mediaspace.illinois.edu/media/t/1_bunb6sak)

[Written report](https://github.com/RessyOwO/OpenFlights/blob/main/results.md)

## **File Descriptions:**

Below are some brief descriptions of our files. Function descriptions can be found in each individual file.

- airports: contains airports class and routes class, along with helper functions
- graph: contains graph class, pagerank, BFS, dijstra's algorithm
- utils: utilities
- main: main function
- tests: test suites
- visuals: visualization

## **How to run:**

In CS225 dev container, in terminal, cd to the folder that you want to store our program in, and do 

```
git clone https://github.com/RessyOwO/OpenFlights.git
```

After the cloning is done, cd to /OpenFlights, then do

```
mkdir build
cd build
cmake ..
```
> **_IMPORTANT!!_**
 Make sure all .txt files has LF as end of line sequence and all IATA codes that you enter should be capitalized!!

Now, the program can be ran by using the './main' executable:

```
make
./main
```

## **Test Description:**

Our tests can be ran with:

```
make test
./test
```

Our tests test the functionality of 
- constructing airports
- constructing routes
- constructing a graph
- Pagerank algorithm
- BFS find shortest path
- Djikstra's algorithm

## **References:**

- [CS225 slides](https://courses.engr.illinois.edu/cs225/fa2022/)
- [Dijkstra's algorithm wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
- [PageRank wikipedia](https://en.wikipedia.org/wiki/PageRank)

## **Team Contract:**

### Communication

#### **Team Meetings** 
    
 We will meet once a week at Wednesday in person at Grainger Library. We will be taking notes on our computer.

#### **Assistance** 

 We will contact each other using wechat or email. We expect a respond time of an hour during weekdays and 48 hours during holidays and weekends.

#### **Respect** 

 To ensure that we have an environment which encourages open expression of ideas, we will be meeting in-person only, since this is the most efficient way to communicate. If we have any disagreements, we will communicate until a compromise can be made. By signing the agreement, it means that all members have agreed on the decisions made.

### Collaboration

#### **Work Distribution** 

At the time of writing this contract, we will split the work equally between us three, since we don't currently know the strengths or weaknesses of us. If unforseen work occurs, we will communicate and assign the work to anyone who have time at the  moment.

#### **Time Commitment** 

 Around 3 hour per week per group member. If unforseen work occurs, Since we will try our best to finish the project early so more time might be needed.we will communicate and assign the work to anyone who have time at the moment. 

#### **Conflict Resolution** 

 If a conflict occurs, we will first try to resolve it within our group, such as communicating with the member and ask if anything is going wrong. Only if we cannot resolve it by ourselves will we ask the course staff for help. 

#### **Signatures**

 Jin Jiang

 Haosen Yao

 Relena Li
