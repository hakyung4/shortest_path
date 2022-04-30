#include "Graph.h"

int main() {
  int line_count = 0;
  std::ifstream File("dataset/data1.txt");
  std::string line;
  while(std::getline(File, line)) {
    line_count++;
  }

  Graph graph;
  // graph.adjBFS[21693]; // error when I use line_count fsr
  

  // BFS
  int startNode = 7;
  int destinationNode = 1;
  graph.addEdge("dataset/data1.txt");
  graph.printGraph(10); // printed only first ten lists
  graph.BFS(startNode, destinationNode, line_count);

  // Dijkstra's
  graph.addEdgeDijkstra("dataset/data1.txt", line_count);
  graph.printPairedGraph(line_count); // printed only first ten lists


  return 0;
}