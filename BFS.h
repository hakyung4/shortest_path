#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
  Graph(int vertex);
  ~Graph();
  void BFS_addEdge(int vertex, int weight);
  void BFS(int start_vertex);

private:
  int vertex_;
  list<int> *adjList;
};