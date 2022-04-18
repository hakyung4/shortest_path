// #include "Graph.h"

// void Graph::addEdge(std::vector<int> adj[], std::string inputFile) {
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

// // A utility function to print the adjacency list
// // representation of graph
// void Graph::printGraph(std::vector<int> adj[], int V) {
//   for (int v = 0; v < V; ++v) {
//     std::cout << "\nAdjacency list of vertex " << v
//               << "\nhead";
//     for (auto x : adj[v])
//       std::cout << " -> " << x;
//     printf("\n");
//   }
// }

// void Graph::BFS(std::vector<int> adj[], int s, int target, int V) {
//   // Mark all the vertices as not visited
//   bool *visited = new bool[V];
//   for (int i = 0; i < V; i++)
//     visited[i] = false;

//   // Create a queue for BFS
//   std::list<int> queue;
//   int distance = 0;

//   // Mark the current node as visited and enqueue it
//   visited[s] = true;
//   queue.push_back(s);

//   // 'i' will be used to get all adjacent
//   // vertices of a vertex
//   std::list<int>::iterator i;

//   while (!queue.empty()) {
//     s = queue.front();
//     queue.pop_front();
//     distance++;

//     // If we found our target destination, return distance
//     if (s == target) {
//       std::cout << std::endl;
//       std::cout << "Target destination found!" << std::endl;
//       std::cout << "Distance = " << distance << std::endl;
//       std::cout << "s = " << s << std::endl;
//       std::cout << "target = " << target << std::endl;
//     }
//     // Get all adjacent vertices of the dequeued
//     // vertex s. If a adjacent has not been visited,
//     // then mark it visited and enqueue it
//     for (auto x : adj[s]) {
//       if (!visited[int(x)]) {
//         visited[int(x)] = true;
//         queue.push_back(x);
//       }
//     }
//   }
// }
