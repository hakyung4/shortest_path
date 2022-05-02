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
  int startnode;
  int endnode;

  std::cout << "Start Node for BFS: ";
  std::cin >> startnode;
  std::cout << "End Node for BFS: ";
  std::cin >> endnode;
  graph.addEdge("dataset/data3.txt");
  graph.printGraph(10);  // printed only first ten lists
  graph.BFS(startnode, endnode, line_count);
  
  
  
  // Dijkstra's
  std::cout << "Start Node for Dijkstra: ";
  std::cin >> startnode;
  std::cout << "End Node for Dijkstra: ";
  std::cin >> endnode;
  std::vector<std::vector<std::pair<int, float> > > adjlis = graph.addEdgeDijkstra("dataset/data3.txt", line_count);
  graph.printPairedGraph(line_count);  // printed only first ten lists
  std::vector<float> dist = graph.Dijkstra("dataset/data3.txt", startnode, endnode);

  return 0;
}