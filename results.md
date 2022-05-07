Algorithms: BFS, Dijkstra, Force Directed Graph

BFS algorithm does a level-order traversal of the graph by implementing a queue. Whatever node it encounters, the node gets pushed into the queue. The first node gets pushed into the queue and each time a node is visited, it is stored in a vector. When visiting a node that wasn't previously visited, the new node that it encounters gets pushed into the queue, and the node that is currently in the queue gets popped. In order to test this algorithm, we made our own data set and chose a short path to traverse and compared it along multiple directions(in a path and its reverse), and we compared the results to check if the BFS algorithm was working.

<img width="1191" alt="Screen Shot 2022-05-06 at 21 02 13" src="https://media.github-dev.cs.illinois.edu/user/11450/files/8ad50132-7aef-4604-90e5-a07dd6210a86">

Dijkstra's algorithm makes use of the assigned weights(the distances in the csv file) to generate the shortest path that can be travelled along the nodes. The function addEdgeDijkstra was used to convert the distances in the csv files to weights of the given edges. In the Dijkstra's algorithm, we make use of adjacency lists containing the edges and the weights to find the shortest path. We first initialize all the sources(vertices). Then, a prioirty queue is created and a source is added where the distance is 0. While the queue is not empty, get a minimum distance vertex from queue. Visit all of its neighbors and choose the neighbor with the smallest weight and update the distance of the path travelled.

<img width="1189" alt="Screen Shot 2022-05-06 at 21 03 51" src="https://media.github-dev.cs.illinois.edu/user/11450/files/e05d40e1-7a80-4de8-bdc6-12f214f8398c">

For the force directed graph, we imported the open sourced d3fdgraph module and then created a table of 3 columns(start node, end node, weight of edge that connects the two nodes). The weights were multiplied by a 1000 to ensure that the graphs didn't have 0 weights. The data was then fed into plot_force_directed_graph function in the module. The thickness of each edge corresponds to the magnitude of the edge's weight. Thicker edges correspond to larger weights. Due to the limited processing capacity of our computers, only 100 nodes were implemented and visualized.

![force_directed](https://media.github-dev.cs.illinois.edu/user/11220/files/84ae14d9-0d38-41f8-a00b-2327ac3400da)

![DIJ_result](https://media.github-dev.cs.illinois.edu/user/11220/files/5066ef27-2238-4db5-b2f8-e8e25079933b)

The runtimes used in the final project are as follows. The runtime of data storage algorithm is O(V+E) where V is the vertices. The runtime of the Breadth First Search algorithm is O(V+E) also. For Dijkstra's algorithm, the runtime is O(V^2). The runtime of force directed graph algorithm is O(n^3) where n is the number of nodes on the graph. The runtimes were verified by using the std::chrono library and observing how the runtimes changed as the amount of data being processed increased. We deduced these runtimes by first analyzing our code (manually deducing how different loops and iterations add to the runtime compplexity), then used the std::chrono library to measure our runtimes for the different functions through different datasets, noting the correlation between the dataset size and the runtime to confirm whether the above runtimes hold true.

The main question of this project was: given a dataset of a speciﬁc area’s road network and assuming ideal conditions (no traﬃc, obstacles, limitations, and uniform speed all throughout), what would be the best algorithm (from among breadth-ﬁrst search and Dijkstra’s algorithm) to deduce the fastest route between two points (road intersection) on a map? After setting up the BFS and Dijkstra's algorithm, we made use of the std::chrono library to test the runtimes of each of the functions. Overall, we found that the Dijkstra's algorithm was able to find the path faster than the BFS algorithm, both in terms of taking edge weights (distances) into account, thus deducing a shorter path than that provided by BFS, but also providing the result in a more efficient and faster runtime.
<img width="1092" alt="Screen Shot 2022-05-06 at 9 16 35 PM" src="https://media.github-dev.cs.illinois.edu/user/10043/files/fe4a0e2c-3618-498e-8096-7a8ab0ee4655">



### Final Presentation Video
https://youtu.be/EbAMA-AcTgk

