#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string line;

  // Access/read from edge dataset
  std::ifstream edge("dataset/cal.cedge.txt");
  if (edge.is_open()) {
    while (std::getline(edge, line)) {
      std::cout << line << std::endl;

      /*
        Data storage - TO DO
      */
    }
    edge.close();
  }

  std::string line2;
  std::ifstream node("dataset/cal.cnode.txt");
  if (node.is_open()) {
    while (std::getline(node, line2)) {
      std::cout << line2 << std::endl;


      /*
        Data storage - TO DO
      */


    }
    node.close();
  }

  return 0;
}