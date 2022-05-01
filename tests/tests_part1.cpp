#include "../cs225/catch/catch.hpp"
// #include "../cs225/catch/catch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stack>
// #include "../cs225/PNG.h"
#include "Graph.h"

using namespace cs225;
using namespace std;


// part1
TEST_CASE("test_addEdge", "[weight=10][part2]")
{
    std::ifstream File("dataset/cal.cedge.txt");
    std::vector<int> adjMat[3];

    addEdge(adjMat, "dataset/cal.cedge.txt");
    REQUIRE(adjMat[0] = 1);
}

