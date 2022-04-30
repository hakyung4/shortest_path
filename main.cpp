// When compiling, as of now, do g++ -std=c++11 main.cpp -o test(you can replace test with whatever you want to call this program) to avoid c++ version conflict
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "BFS.cpp"
#include "Graph.h"

void addWeight(std::string inputFile) {
  std::ifstream File(inputFile);
  if (!File) {
    std::cout << "can't open the file" << std::endl;
  }

  std::vector<int> edgeId;
  std::vector<int> startNode;
  std::vector<int> endNode;
  std::vector<float> weight;
  int n1, n2, n3;
  float n4;

  while (File >> n1 >> n2 >> n3 >> n4) {
    edgeId.push_back(n1);
    startNode.push_back(n2);
    endNode.push_back(n3);
    weight.push_back(n4);
  }
  // std::cout << "Start, End, Distance : ";
  for (int i = 0; i < startNode.size(); i++) {
    std::cout << "Start, End, Distance : " << std::endl;
    std::cout << startNode[i] << std::endl;
    std::cout << endNode[i] << std::endl;
    std::cout << weight[i] << std::endl;
  }
}

// void addEdge(std::vector<int> adj[], std::string inputFile) {
//   std::ifstream File(inputFile);
//   std::string line;
//   while (std::getline(File, line)) {
//     int node1;
//     int node2;
//     int temp;

//     std::stringstream ss(line);
//     ss >> temp;
//     ss >> node1;
//     ss >> node2;

//     // add to matrix
//     adj[node1].push_back(node2);
//     adj[node2].push_back(node1);
//   }
// }

// A utility function to print the adjacency list
// representation of graph
// void printGraph(std::vector<int> adj[], int V) {
//   for (int v = 0; v < V; ++v) {
//     std::cout << "\nAdjacency list of vertex " << v
//               << "\nhead";
//     for (auto x : adj[v])
//       std::cout << " -> " << x;
//     printf("\n");
//   }
// }

/*void BFS(std::vector<int> adj[], int s, int target, int V) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;
  // Create a queue for BFS
  std::list<int> queue;
  int distance = 0;
  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);
  // 'i' will be used to get all adjacent
  // vertices of a vertex
  std::list<int>::iterator i;
  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    distance++;
    // If we found our target destination, return distance
    if (s == target) {
      std::cout << std::endl;
      std::cout << "Target destination found!" << std::endl;
      std::cout << "Distance = " << distance << std::endl;
      std::cout << "s = " << s << std::endl;
      std::cout << "target = " << target << std::endl;
    }
    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (auto x : adj[s]) {
      if (!visited[int(x)]) {
        visited[int(x)] = true;
        queue.push_back(x);
      }
    }
  }
}
*/

int main() {
  // get the total number of lines of cedge file
  // int line_count = 0;
  // std::ifstream File("dataset/cal.cedge.txt");
  // std::string line;
  // while (std::getline(File, line)) {
  //   line_count++;
  // }

  std::vector<int> adjMat[21693];  // error when I use line_count fsr

  addWeight("dataset/cal.cedge.txt");

  // printing to check BFS is working
  // Graph g(4);
  // g.BFS_addEdge(0, 1);
  // g.BFS_addEdge(0, 2);
  // g.BFS_addEdge(1, 2);
  // g.BFS_addEdge(2, 0);
  // g.BFS_addEdge(2, 3);

  // std::cout << "Following is Breadth First Traversal " << "(starting from vertex 2) " << std::endl;
  // g.BFS(2);

  return 0;
}




// // Program to find Dijkstra's shortest path using
// // priority_queue in STL
// #include <algorithm>
// #include <fstream>
// #include <iomanip>
// #include <iostream>
// #include <list>
// #include <queue>
// #include <sstream>
// #include <string>
// #include <unordered_map>
// #include <vector>

// using namespace std;
// # define INF 0x3f3f3f3f

// // iPair ==> Integer Pair
// typedef pair<int, int> iPair;

// // This class represents a directed graph using
// // adjacency list representation
// class Graph
// {
// 	int V; // No. of vertices

// 	// In a weighted graph, we need to store vertex
// 	// and weight pair for every edge
// 	list< pair<int, int> > *adj;

// public:
// 	Graph(int V); // Constructor

// 	// function to add an edge to graph
// 	void addEdge(int u, int v, int w);

// 	// prints shortest path from s
// 	void shortestPath(int s);
// };

// // Allocates memory for adjacency list
// Graph::Graph(int V)
// {
// 	this->V = V;
// 	adj = new list<iPair> [V];
// }

// void Graph::addEdge(int u, int v, int w)
// {
// 	adj[u].push_back(make_pair(v, w));
// 	adj[v].push_back(make_pair(u, w));
// }

// // Prints shortest paths from src to all other vertices
// void Graph::shortestPath(int src)
// {
// 	// Create a priority queue to store vertices that
// 	// are being preprocessed. This is weird syntax in C++.
// 	// Refer below link for details of this syntax
// 	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// 	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

// 	// Create a vector for distances and initialize all
// 	// distances as infinite (INF)
// 	vector<int> dist(V, INF);

// 	// Insert source itself in priority queue and initialize
// 	// its distance as 0.
// 	pq.push(make_pair(0, src));
// 	dist[src] = 0;

// 	/* Looping till priority queue becomes empty (or all
// 	distances are not finalized) */
// 	while (!pq.empty())
// 	{
// 		// The first vertex in pair is the minimum distance
// 		// vertex, extract it from priority queue.
// 		// vertex label is stored in second of pair (it
// 		// has to be done this way to keep the vertices
// 		// sorted distance (distance must be first item
// 		// in pair)
// 		int u = pq.top().second;
// 		pq.pop();

// 		// 'i' is used to get all adjacent vertices of a vertex
// 		list< pair<int, int> >::iterator i;
// 		for (i = adj[u].begin(); i != adj[u].end(); ++i)
// 		{
// 			// Get vertex label and weight of current adjacent
// 			// of u.
// 			int v = (*i).first;
// 			int weight = (*i).second;

// 			// If there is shorted path to v through u.
// 			if (dist[v] > dist[u] + weight)
// 			{
// 				// Updating distance of v
// 				dist[v] = dist[u] + weight;
// 				pq.push(make_pair(dist[v], v));
// 			}
// 		}
// 	}

// 	// Print shortest distances stored in dist[]
// 	printf("Vertex Distance from Source\n");
// 	for (int i = 0; i < V; ++i)
// 		printf("%d \t\t %d\n", i, dist[i]);
// }

// // Driver program to test methods of graph class
// int main()
// {
// 	// create the graph given in above figure
// 	int V = 21692;
// 	Graph g(V);

// 	// making above shown graph
//   for (unsigned i = 0; i < V; i++) {
//     g.addEdge()
//   }
// 	g.addEdge(0, 1, 4);
// 	g.addEdge(0, 7, 8);
// 	g.addEdge(1, 2, 8);
// 	g.addEdge(1, 7, 11);
// 	g.addEdge(2, 3, 7);
// 	g.addEdge(2, 8, 2);
// 	g.addEdge(2, 5, 4);
// 	g.addEdge(3, 4, 9);
// 	g.addEdge(3, 5, 14);
// 	g.addEdge(4, 5, 10);
// 	g.addEdge(5, 6, 2);
// 	g.addEdge(6, 7, 1);
// 	g.addEdge(6, 8, 6);
// 	g.addEdge(7, 8, 7);

// 	g.shortestPath(0);

// 	return 0;
// }

