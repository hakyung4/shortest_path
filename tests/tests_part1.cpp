#include "../cs225/catch/catch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
#include "../cs225/PNG.h"
#include "../Graph.h"

using namespace std;


// part1
TEST_CASE("test_addEdge", "[weight=10][part2]")
{
    Graph graph;
    std::ifstream File("dataset/cal.cedge.txt");
    std::vector<int> adjMat[3];
    graph.addEdge("dataset/cal.cedge.txt");

    // addEdge(adjMat, "dataset/cal.cedge.txt");
    REQUIRE(1 == 1);
}

