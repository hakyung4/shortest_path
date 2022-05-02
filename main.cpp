#include "Graph.h"

int main() {
  int line_count = 0;
  std::ifstream File("dataset/data1.txt");
  std::string line;
  while (std::getline(File, line)) {
    line_count++;
  }

  Graph graph;
  // graph.adjBFS[21693]; // error when I use line_count fsr

  // BFS
  int startNode = 7;
  int destinationNode = 1;
  graph.addEdge("dataset/data3.txt");
  graph.printGraph(10);  // printed only first ten lists
  graph.BFS(startNode, destinationNode, line_count);

  // Dijkstra's
  std::vector<std::vector<std::pair<int, float> > > adjlis = graph.addEdgeDijkstra("dataset/data3.txt", line_count);
  graph.printPairedGraph(line_count);  // printed only first ten lists
  int node = 9;
  int node2 = 1;
  std::vector<float> dist = graph.Dijkstra("dataset/data3.txt", node, node2);

  return 0;
}