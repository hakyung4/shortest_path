#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string line;
  const char comma = ',';
  std::string word;
  std::ifstream in("dataset/cal.cedge.txt");
  std::ofstream out("edge.csv");

  if (!in) {
    std::cout << "can't open!" << std::endl;
  }

  while (std::getline(in, line)) {
    std::stringstream ss(line);
    bool first = true;
    while (ss >> word) {
      if (!first) out << comma;
      out << word;
      first = false;
    }
    out << std::endl;
  }

  in.close();
  out.close();

  std::string line2;
  const char comma2 = ',';
  std::string word2;
  std::ifstream in2("dataset/cal.cnode.txt");
  std::ofstream out2("node.csv");

  if (!in2) {
    std::cout << "can't open!" << std::endl;
  }

  while (std::getline(in2, line2)) {
    std::stringstream ss2(line2);
    bool first2 = true;
    while (ss2 >> word2) {
      if (!first2) out2 << comma2;
      out2 << word2;
      first2 = false;
    }
    out2 << std::endl;
  }

  in2.close();
  out2.close();

  
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