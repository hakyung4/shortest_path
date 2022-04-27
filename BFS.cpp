// #include "BFS.h"

// Graph::Graph(int vertex) {
//   this->vertex_ = vertex;
//   adjList = new list<int>[vertex];
// }

// Graph::~Graph() {
// }

// void Graph::BFS_addEdge(int vertex, int weight) {
//   adjList[vertex].push_back(weight);
// }

// void Graph::BFS(int start_vertex) {
//   bool *visited = new bool[vertex_];

//   // initially setting all to not visited
//   for (int i = 0; i < vertex_; i++) {
//     visited[i] = false;
//   }

//   std::list<int> BFS_queue;

//   // when visited - mark true
//   visited[start_vertex] = true;
//   BFS_queue.push_back(start_vertex);

//   list<int>::iterator i;

//   while (!BFS_queue.empty()) {
//     start_vertex = BFS_queue.front();
//     BFS_queue.pop_front();

//     // getting all adjacent vertices
//     for (i = adjList[start_vertex].begin(); i != adjList[start_vertex].end(); ++i) {
//       if (!visited[*i]) {
//         visited[*i] = true;
//         BFS_queue.push_back(*i);
//       }
//     }
//   }
// }