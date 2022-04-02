# Team: Electrical and Computer Engineers

### CS225 Final Project SP 2022

## Introduction and Leading question

Throughout the past few decades, the rise in use of vehicles has become indispensable in major cities,resulting in the expansion of roads networks and routes. This resulted in the increasing complexity and diﬃculty ofdeciding on the best route to take whilst minimizing time. This problem is relevant within two instances: the mostcommon scenario of a human deciding on the fastest route to take between two points on the map, but morerecently applicable to autonomous vehicles.

A question then arises: given an undirected dataset of a speciﬁc area’s road network and assumingideal conditions (no traﬃc, obstacles, limitations, and uniform speed all throughout), what would be the bestalgorithm (from among breadth-ﬁrst search and Dijkstra’s algorithm) to deduce the fastest route between twopoints (road intersection) on a map?

To further explore this question and land at an accurate answer/solution to the above problem, we havedecided to use the California Road Network[1] as our dataset as it provides an undirected network with nodesrepresenting road intersections and edges representing roads connecting these intersections. The datasetprovides this data as a set of two columns that depict the nodes that have an edge between them. This would bea great dataset to base our investigation on as it provides a real-world location that embodies the problem we’readdressing with regards to complexity of routes and traﬃc, but it also stands as an exciting challenge as itrequires our team to solve the challenging problems of suitably processing, storing, visualizing such a dataset in asuitable way to implement our algorithms and answer our leading question.

As for algorithms, our decision to use breadth-ﬁrst search and Dijkstra’s algorithm to attempt to answer ourleading question as well as force-directed graphs to allow us to represent our data stems from our knowledgefrom previous units as well as our research on the topic as these algorithms have been hypothesized to beeﬀective in ﬁnding the shortest path between two nodes of an undirected graph, thus proving relevant to ourleading question. After ﬁrst processing and storing our data in a suitable manner, we will use these algorithmsalongside a counter for how many nodes have been traversed to ﬁnd the diameter (shortest path) between two nodes as well as a way to track the elapsed time (an std module), comparing the time it took for eachalgorithm to land at the answer.

## Dataset acquisition and Processing

- Data format: We acquired the dataset from [Real Datasets for Spatial Databases: Road Networks and Points of Interest](https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm). We decided to use the first two given datasets because they have all the essential information we need such as real distance between two nodes. The datasets represent a road network in California. The input format of the datasets is in .txt. We plan to use all of the given data.

- Data correction: 

- Data Storage: 

## Implementation Plan
We plan to use force directed graph drawing to represent our data, then use breadth-ﬁrst search and Dijkstra’s algorithm as means to ﬁnd the diameter (shortest path) between two nodes.

Highlighted below are more details for each algorithm:
  - Breadth First Search (covered in class)
    - Input: nodes and edges given in the .txt ﬁle
    - Output shown: using Force directed graph drawing
    - By using force directed graph drawing, it would show the path from the start to the destination.
    - Function eﬃciency: Targets on O(V + E); V = vertices(nodes) on graph, E = edges on graph

  - Dijkstra’s Algorithm (covered in class)
    - Input: nodes and edges given in the .txt ﬁle
    - Output shown: using Force directed graph drawing
    - By using force directed graph drawing, it would show the path from the start to the destination.
    - Function eﬃciency: Targets on O(V^2); V = vertices(nodes) on graph

  - Force directed graph drawing (not covered in class)
    - Input: ﬁle containing relevant data (may need to be modiﬁed to diﬀerent ﬁle type, possibly a csv)
    - Output shown: graph
    - Function eﬃciency: Targets on O(n^3); n = number of nodes on graph

## Timeline
Our ﬁnal deliverable goals are as follows:
  - A visualization of our dataset represented as graph of all the nodes and edges
  - A set of functions that ﬁnd the shortest path using BFS
  - A set of functions that ﬁnd the shortest path using Dijkstra’s Algorithm
  - A function/ set of functions that color the shortest path
  - A table and graph that highlights the time it took for each function to land at the shortest path
  - Unique data structures representing the graph and its elements (edges,nodes,etc.)

 Planning ahead, we divided our investigation into several major milestones, setting a proposed timeline for each task.
  - Data acquisition, processing and visualization (April 3, 2022)
  - Establish project directory, foundation, and major ﬁles
  - Access dataset successfully
  - Come up with methods to store and visualize data
  - Finish Force-Directed Graph that represents all the data (April 10, 2022)
  - Finish 1st Shortest Path Algorithm (BFS or Dijkstra’s) (April 24, 2022)
  - Finish 2nd Shortest Path Algorithm (May 3, 2022)
  - Finish Presentation + Report (May 6, 2022)