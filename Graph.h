#pragma once

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <queue>


class Graph {
public:
  void set_startNode(std::vector<int> startNode);
  void set_endNode(std::vector<int> endNode);
  void set_weight(std::vector<float> weight);
  void addWeight(std::string inputFile, std::vector<int> startNode, std::vector<int> endNode, std::vector<float> weight);
  std::vector<int> get_startNode();
  std::vector<int> get_endNode();
  std::vector<float> get_weight();

  // BFS
  void addEdge(std::string inputFile);
  void BFS(int s, int target, int V);
  void printGraph(int V);

  // Dijkstra
  void addEdgeDijkstra (std::string inputFile, int V);
  void Dijkstra(int s, int target, int V);
  void printPairedGraph(int V);

  std::vector<int> adjBFS[21693];
  std::vector< std::vector< std::pair<int, float> > > adjDij;


private:
  int vertex_;
  std::vector<int> startNode_;
  std::vector<int> endNode_;
  std::vector<float> weight_;
};