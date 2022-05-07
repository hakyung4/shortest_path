#include "Graph.h"
#include "cmath"
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

TEST_CASE("test_addEdge", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  graph.addEdgeBFS(filename);

  REQUIRE(graph.adjBFS[0][0] == 1);
}

TEST_CASE("BFS", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }
  int startNode = 1;
  int endNode = 6;

  graph.addEdgeBFS(filename);
  int result = graph.BFS(startNode, endNode, line_count);

  REQUIRE(result == 2);
}

TEST_CASE("BFS2", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }
  int startNode = 1023;
  int endNode = 850;

  graph.addEdgeBFS(filename);
  int result = graph.BFS(startNode, endNode, line_count);

  REQUIRE(result == 120);
}

TEST_CASE("BFS3", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }
  int startNode = 1942;
  int endNode = 1;

  graph.addEdgeBFS(filename);
  int result = graph.BFS(startNode, endNode, line_count);

  REQUIRE(result == 145);
}

TEST_CASE("BFS4", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }
  int startNode = 10000;
  int endNode = 21052;

  graph.addEdgeBFS(filename);
  int result = graph.BFS(startNode, endNode, line_count);

  REQUIRE(result == 0);
}

TEST_CASE("test_addEdgeDij", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }

  graph.addEdgeDijkstra(filename, line_count);

  int actual_node = graph.adjDij[0][1].first;
  float actual_weight = graph.adjDij[0][1].second;

  float expected_weight = 0.005952;

  actual_weight = std::trunc(actual_weight);
  expected_weight = std::trunc(expected_weight);

  REQUIRE(actual_node == 6);
  REQUIRE(actual_weight == expected_weight);
}

TEST_CASE("Dijkstra", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }

  int startNode = 100;
  int endNode = 650;
  graph.addEdgeDijkstra(filename, line_count);
  float distance = graph.Dijkstra(filename, startNode, endNode);
  float expected = 3.8355898857;
  distance = std::trunc(distance);
  expected = std::trunc(expected);
  REQUIRE(distance == expected);
}

TEST_CASE("Dijkstra2", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }

  int startNode = 18592;
  int endNode = 5219;
  graph.addEdgeDijkstra(filename, line_count);
  float distance = graph.Dijkstra(filename, startNode, endNode);
  float expected = 13.9514;
  distance = std::trunc(distance);
  expected = std::trunc(expected);
  bool correctValue = (distance == expected);
  REQUIRE(distance == expected);
}

TEST_CASE("Dijkstra3", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }

  int startNode = 20154;
  int endNode = 10293;
  graph.addEdgeDijkstra(filename, line_count);
  float distance = graph.Dijkstra(filename, startNode, endNode);
  float expected = 11.2701;
  distance = std::trunc(distance);
  expected = std::trunc(expected);
  bool correctValue = (distance == expected);
  REQUIRE(distance == expected);
}

TEST_CASE("Dijkstra4", "[weight=10]") {
  Graph graph;
  string filename = "dataset/cal.cedge.txt";
  int line_count = 0;
  ifstream File(filename);
  string line;
  while (getline(File, line)) {
    line_count++;
  }

  int startNode = 1029;
  int endNode = 1;
  graph.addEdgeDijkstra(filename, line_count);
  float distance = graph.Dijkstra(filename, startNode, endNode);
  float expected = 0.962264;
  distance = std::trunc(distance);
  expected = std::trunc(expected);
  bool correctValue = (distance == expected);
  REQUIRE(distance == expected);
}