#include "Graph.h"

int main() {
  int line_count = 0;
  std::ifstream File("dataset/cal.cedge.txt");
  std::string line;
  while (std::getline(File, line)) {
    line_count++;
  }

  std::vector<int> adjMat[21693]; // error when I use line_count fsr
  std::vector<std::vector<std::pair<int, int>>> adjDijkstra[21693]; // error when I use line_count fsr

  
  Graph graph;

  graph.addEdge(adjMat, "dataset/cal.cedge.txt");

  graph.printGraph(adjMat, 10); // printed only first ten lists

  int startNode = 5;
  int destinationNode = 252;
  graph.BFS(adjMat, startNode, destinationNode, line_count);

  return 0;
}