// When compiling, as of now, do g++ -std=c++11 main.cpp -o test(you can replace test with whatever you want to call this program) to avoid c++ version conflict
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"

void addEdge(std::vector<int> adj[], std::string inputFile) {
  std::ifstream File(inputFile);
  std::string line;
  while (std::getline(File, line)) {
    int node1;
    int node2;
    int temp;

    std::stringstream ss(line);
    ss >> temp;
    ss >> node1;
    ss >> node2;

    // add to matrix
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
  }
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(std::vector<int> adj[], int V) {
  for (int v = 0; v < V; ++v) {
    std::cout << "\nAdjacency list of vertex " << v
              << "\nhead";
    for (auto x : adj[v])
      std::cout << " -> " << x;
    printf("\n");
  }
}

void BFS(std::vector<int> adj[], int s, int target, int V) {
  // Mark all the vertices as not visited
  bool *visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  // Create a queue for BFS
  std::list<int> queue;
  int distance = 0;

  // Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);

  // 'i' will be used to get all adjacent
  // vertices of a vertex
  std::list<int>::iterator i;

  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    distance++;

    // If we found our target destination, return distance
    if (s == target) {
      std::cout << std::endl;
      std::cout << "Target destination found!" << std::endl;
      std::cout << "Distance = " << distance << std::endl;
      std::cout << "s = " << s << std::endl;
      std::cout << "target = " << target << std::endl;
    }
    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it
    for (auto x : adj[s]) {
      if (!visited[int(x)]) {
        visited[int(x)] = true;
        queue.push_back(x);
      }
    }
  }
}

int main() {
  int line_count = 0;
  std::ifstream File("dataset/cal.cedge.txt");
  std::string line;
  while (std::getline(File, line)) {
    line_count++;
  }

  std::vector<int> adjMat[21693];  // error when I use line_count fsr
  // Graph adj[21693];
  addEdge(adjMat, "dataset/cal.cedge.txt");
  // adj->addEdge(adj, "dataset/cal.cedge.txt");
  // adj->printGraph(adj, 20);
  // printGraph(adjMat, 20);

  int startNode = 102;
  int destinationNode = 565;
  // adj->BFS(adj, startNode, destinationNode, line_count);
  BFS(adjMat, startNode, destinationNode, line_count);

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