#include "Graph.h"
#include "cs225/PNG.h"
#include "cs225/catch/catch.hpp"

using namespace std;
using namespace cs225;

/*
To compile, copy each to the terminal seperately:

make

clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o cs225/catch/catchmain.o

clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c test1.cpp -o .objs/test1.o

clang++ .objs/Graph.o .objs/test1.o cs225/catch/catchmain.o  -std=c++14 -stdlib=libc++ -lc++abi -o test

./test

*/

// part1
TEST_CASE("test_addEdge", "[weight=10]") {
  Graph graph;
  string filename = "dataset/data1.txt";
  graph.addEdgeBFS(filename);

  REQUIRE(graph.adjBFS[0][0] == 1);
}

TEST_CASE("BFS", "[weight=10]") {
  Graph graph;
  string filename = "dataset/data1.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }
  int startNode = 1;
  int endNode = 6;

  graph.BFS(startNode, endNode, line_count);

  REQUIRE(graph.BFS(startNode, endNode, line_count) == 2);
}

// TEST_CASE("Dijkstra", "[weight=10]") {
//   Graph graph;
//   string filename = "dataset/data1.txt";
//   int startNode = 1;
//   int endNode = 6;

//   graph.Dijkstra(filename, startNode, endNode);
    // No conversion from std::vector<float> to double...
//   std::vector<float> dist = 0.007977;

//   REQUIRE(graph.Dijkstra(filename, startNode, endNode) == dist);
// }

// TEST_CASE("addEdgeDijkstra", "[weight=10]") {
//   Graph graph;
//   string filename = "dataset/data1.txt";
//   int line_count = 0;
//   ifstream File(filename);
//   string line;
//   while (getline(File, line)) {
//     line_count++;
//   }
    // invalid operands to binary expression ('std::vector<std::vector<std::pair<int, float>>>' and 'int')
//   graph.addEdgeDijkstra(filename, line_count);
    
//   REQUIRE(graph.addEdgeDijkstra(filename, line_count) == 1);
// }
