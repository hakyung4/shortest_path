Algorithms: BFS, Dijkstra, Force Directed Graph

BFS algorithm does a level-order traversal of the graph by implementing a queue. Whatever node it encounters, the node gets pushed into the queue. The first node gets pushed into the queue and each time a node is visited, it is stored in a vector. When visiting a node that wasn't previously visited, the new node that it encounters gets pushed into the queue, and the node that is currently in the queue gets popped. In order to test this algorithm, we made our own data set and chose a short path to traverse and compared it along multiple directions(in a path and its reverse), and we compared the results to check if the BFS algorithm was working.

//attach test case visualization here

Dijkstra's algorithm makes use of the assigned weights(the distances in the csv file) to generate the shortest path that can be travelled along the nodes. The function addEdgeDijkstra was used to convert the distances in the csv files to weights of the given edges. In the Dijkstra's algorithm, we make use of adjacency lists containing the edges and the weights to find the shortest path. We first initialize all the sources(vertices). Then, a prioirty queue is created and a source is added where the distance is 0. While the queue is not empty, get a minimum distance vertex from queue. Visit all of its neighbors and choose the neighbor with the smallest weight and update the distance of the path travelled.

//attach test case visualization here

For the force directed graph, we imported the open sourced d3fdgraph module and then created a table of 3 columns(start node, end node, weight of edge that connects the two nodes). The weights were multiplied by a 1000 to ensure that the graphs didn't have 0 weights. The data was then fed into plot_force_directed_graph function in the module. Due to the limited processing capacity of our computers, only 100 nodes were implemented and visualized.

//attach test case visualization here

The main question of this project was: given a dataset of a speciﬁc area’s road network and assuming ideal conditions (no traﬃc, obstacles, limitations, and uniform speed all throughout), what would be the best algorithm (from among breadth-ﬁrst search and Dijkstra’s algorithm) to deduce the fastest route between two points (road intersection) on a map? After setting up the BFS and Dijkstra's algorithm, we made use of the std::chrono library to test the runtimes of each of the functions. Overall, we found that the Dijkstra's algorithm was able to find the path faster than the BFS algorithm.

//attach test case visualization here.
