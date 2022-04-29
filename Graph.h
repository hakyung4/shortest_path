#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

class Graph {
public:
  void addEdge(std::vector<int> adj[], std::string inputFile);
  void printGraph(std::vector<int> adj[], int V);
  void BFS(std::vector<int> adj[], int s, int target, int V);
  void addWeight(std::string inputFile, std::vector<int> startNode, std::vector<int> endNode, std::vector<float> weight);
  void set_startNode(std::vector<int> startNode);
  void set_endNode(std::vector<int> endNode);
  void set_weight(std::vector<float> weight);
  std::vector<int> get_startNode();
  std::vector<int> get_endNode();
  std::vector<float> get_weight();

private:
  int vertex_;
  std::list<int> *adjList;
  std::vector<int> startNode_;
  std::vector<int> endNode_;
  std::vector<float> weight_;
};