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
  std::vector< std::vector< std::pair<int, float> > > adjlis = graph.addEdgeDijkstra("dataset/data1.txt", line_count);
  graph.printPairedGraph(line_count); // printed only first ten lists
  int node = 0;
  std::vector<float> dist = graph.Dijkstra("dataset/data1.txt", adjlis, node);
  for (unsigned i = 0; i < dist.size(); i++) {
    std::cout << "The distance from node " << node << " to node " << i << " is: " << dist[i] << std::endl;
  }

  return 0;
}