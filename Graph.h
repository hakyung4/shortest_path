#pragma once

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class Graph {
public:
  // BFS
  void addEdgeBFS(std::string inputFile);
  int BFS(int s, int target, int V);
  void printGraph(int V);

  // Dijkstra
  std::vector<std::vector<std::pair<int, float> > > addEdgeDijkstra(std::string inputFile, int V);
  float Dijkstra(std::string inputFile, int &start, int &end);
  void printPairedGraph(int V);

  std::vector<int> adjBFS[21693];
  std::vector<std::vector<std::pair<int, float> > > adjDij;
};