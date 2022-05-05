#include "Graph.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
  int line_count = 0;
  std::string filename = "dataset/data1.txt";
  std::ifstream File(filename);
  std::string line;
  while(std::getline(File, line)) {
    line_count++;
  }

  Graph graph;
  int startNode;
  int destinationNode;
  

  // BFS
  std::cout << "\n\n----------- BFS -----------\n";
  std::cout << "Start Node for BFS: ";
  std::cin >> startNode;
  std::cout << "End Node for BFS: ";
  std::cin >> destinationNode;

  graph.addEdgeBFS(filename);
  // graph.printGraph(10); // printed only first ten lists
  auto start = high_resolution_clock::now();
  graph.BFS(startNode, destinationNode, line_count);
  auto stop = high_resolution_clock::now();

  // Dijkstra's
  std::cout << "\n\n----------- Dijkstra -----------\n";
  std::cout << "Start Node for Dijkstra: ";
  std::cin >> startNode;
  std::cout << "End Node for Dijkstra: ";
  std::cin >> destinationNode;

  graph.addEdgeDijkstra(filename, line_count);
  // graph.printPairedGraph(line_count); 
  auto start_d=high_resolution_clock::now();
  graph.Dijkstra(filename, startNode, destinationNode);
  auto stop_d=high_resolution_clock::now();


  std::cout << "\n\n\n----------- End Results -----------\n";
  auto duration = duration_cast<microseconds>(stop - start);
  std::cout << "Time taken by BFS function: "<< duration.count() << " microseconds" << std::endl;
  auto duration_d = duration_cast<microseconds>(stop_d - start_d);
  std::cout << "Time taken by Dijkstra's function: "<< duration_d.count() << " microseconds" << std::endl;
  
  std::cout << std::endl;

  return 0;
}