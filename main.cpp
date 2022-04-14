#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void addEdge(std::vector<int> adj[], std::string inputFile) {
  std::ifstream File(inputFile);
  std::string line;
  while(std::getline(File, line)) {
    int node1;
    int node2;
    
    std::stringstream ss(line);
    ss >> node1;
    ss >> node2;

    std::cout << "Start node: " << node1 << " " << std::endl;
    std::cout << "End node: " << node2 << " " << std::endl;
    std::cout << "\n";
  }
}

int main() {
  int line_count = 0;
  std::ifstream File("dataset/cal.cedge.txt");
  std::string line;
  while(std::getline(File, line)) {
    line_count++;
  }

  std::vector<int> adj[line_count];
  addEdge(adj, "dataset/cal.cedge.txt");


  // std::string line;
  // const char comma = ',';
  // std::string word;
  // std::ifstream in("dataset/cal.cedge.txt");
  // std::ofstream out("edge.csv");

  // if (!in) {
  //   std::cout << "can't open!" << std::endl;
  // }

  // while (std::getline(in, line)) {
  //   std::stringstream ss(line);
  //   bool first = true;
  //   while (ss >> word) {
  //     if (!first) out << comma;
  //     out << word;
  //     first = false;
  //   }
  //   out << std::endl;
  // }

  // in.close();
  // out.close();

  // std::string line2;
  // const char comma2 = ',';
  // std::string word2;
  // std::ifstream in2("dataset/cal.cnode.txt");
  // std::ofstream out2("node.csv");

  // if (!in2) {
  //   std::cout << "can't open!" << std::endl;
  // }

  // while (std::getline(in2, line2)) {
  //   std::stringstream ss2(line2);
  //   bool first2 = true;
  //   while (ss2 >> word2) {
  //     if (!first2) out2 << comma2;
  //     out2 << word2;
  //     first2 = false;
  //   }
  //   out2 << std::endl;
  // }

  // in2.close();
  // out2.close();

  
  // Access/read from edge dataset
  // std::ifstream edge("dataset/cal.cedge.txt");
  // if (edge.is_open()) {
  //   while (std::getline(edge, line)) {
  //     std::cout << line << std::endl;

  //     /*
  //       Data storage - TO DO
  //     */
  //   }
  //   edge.close();
  // }

  // std::string line2;
  // std::ifstream node("dataset/cal.cnode.txt");
  // if (node.is_open()) {
  //   while (std::getline(node, line2)) {
  //     std::cout << line2 << std::endl;

  //     /*
  //       Data storage - TO DO
  //     */

  //   }
  //   node.close();
  // }

  return 0;
}