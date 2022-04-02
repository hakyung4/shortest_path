#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string line;
  std::ifstream edge("dataset/cal.cedge.txt");
  if (edge.is_open()) {
    while (std::getline(edge, line)) {
      std::cout << line << std::endl;
    }
    edge.close();
  }

  std::string line2;
  std::ifstream node("dataset/cal.cnode.txt");
  if (node.is_open()) {
    while (std::getline(node, line2)) {
      std::cout << line2 << std::endl;
    }
    node.close();
  }

  return 0;
}