#include "Graph.h"

//void Graph::addWeight(std::string inputFile, std::vector<int> startNode, std::vector<int> endNode, std::vector<float> weight) {
std::vector<float> Graph::addWeight(std::string inputFile) { 
  std::ifstream File(inputFile);
  std::vector<int> startNode;
  std::vector<int> endNode;
  std::vector<float> weight;
  if (!File) {
    std::cout << "can't open the file" << std::endl;
  }
  std::vector<int> edgeId;
  int n1, n2, n3;
  float n4;

  while (File >> n1 >> n2 >> n3 >> n4) {
    edgeId.push_back(n1);
    startNode.push_back(n2);
    endNode.push_back(n3);
    weight.push_back(n4);
  }

  for (int i = 0; i < int(startNode.size()); i++) {
    std::cout << "Start, End, Distance : " << std::endl;
    std::cout << startNode[i] << std::endl;
    std::cout << endNode[i] << std::endl;
    std::cout << weight[i] << std::endl;
  }
  return weight;
}

void Graph::addEdge(std::string inputFile) {
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
    adjBFS[node1].push_back(node2);
    adjBFS[node2].push_back(node1);
  }
}

std::vector< std::vector<std::pair<int, float> > > Graph::addEdgeDijkstra(std::string inputFile, int V) {
  std::ifstream File(inputFile);
  std::string line;

  for (int i = 0; i < V; i++) {
    // Create a vector to represent a row, and add it to the adjList.
    std::vector<std::pair<int, float> > row;
    adjDij.push_back(row);
  }

  while (std::getline(File, line)) {
    int temp;
    int node1;
    int node2;
    float weight;

    std::stringstream ss(line);
    ss >> temp;
    ss >> node1;
    ss >> node2;
    ss >> weight;

    adjDij[node1].push_back(std::make_pair(node2, weight));
    adjDij[node2].push_back(std::make_pair(node1, weight));
  }
  return adjDij;
}

std::vector<float> Graph::Dijkstra(std::string inputFile, std::vector<std::vector<std::pair<int, float> > > &adjList, int &start) {
  std::cout << "Shortest path: " << std::endl;
  int n = adjList.size();

  // The way we are copying weight vector is not right. We are tryna add weights so that it's gonna look something like
  // "from this node to that node, the weight is ______." But, the way we are copying it, it's doing like 
  // "for this edge ID, the weight(distance) is ______." We aren't sure how to fix it.
  std::vector<float> weight;
  for (unsigned i = 0; i < addWeight(inputFile).size(); i++) {
    weight.push_back(addWeight(inputFile)[i]);
  }

  for (unsigned i = 0; i < weight.size(); i++) {
    std::cout << "weight for node " << i << " is " << weight[i] << std::endl;
  }
  
  
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
  pq.push(std::make_pair(start, 0));
  weight[start] = 0;

  while (pq.empty() == false) {
    int u = pq.top().first;
    pq.pop();
    int n = adjList[u].size();

    for (int i = 0; i < n; i++) {
      float v = adjList[u][i].first;
      float wt = adjList[u][i].second;

      if (weight[v] > weight[u] + wt) {
        weight[v] = weight[u] + wt;
        pq.push(std::make_pair(v, weight[v]));
      }
    }
  }
  return weight;
}

void Graph::printPairedGraph(int V) {
  std::cout << "\n__________ Dijkstra's ____________\n"
            << std::endl;

  for (int v = 0; v < V; ++v) {
    std::cout << "\nAdj Dijkstra's list of vertex " << v
              << "\nhead";

    for (auto x : adjDij[v]) {
      std::cout << " -> " << x.first;
    }
    printf("\n");
  }
  printf("\n\n\n");
}

// A utility function to print the adjacency list
// representation of graph
void Graph::printGraph(int V) {
  for (int v = 0; v < V; ++v) {
    std::cout << "\nAdjacency list of vertex " << v
              << "\nhead";
    for (auto x : adjBFS[v]) {
      std::cout << " -> " << x;
    }
    printf("\n");
  }
}

void Graph::BFS(int s, int target, int V) {
  // Path vector to store directions
  std::vector<int> path;

  // Store prev cells in a vector, resize, set all to -1
  std::vector<int> prevCells;
  prevCells.resize(V, -1);

  // Lengths will allow us to store the different lengths, to be used later
  // Helped simplify the implementation
  // resize to size and set all to -1
  std::vector<int> lengths;
  lengths.resize(V, 0);

  // Create a queue for BFS
  std::queue<int> queue;

  // Mark all the vertices as not visited
  std::vector<bool> visited;
  visited.resize(V, false);

  // Use a stack to store directions, to be dumped into the path vector later
  std::stack<int> directions;

  // 'i' will be used to get all adjacent
  // vertices of a vertex
  std::list<int>::iterator i;

  // Mark the current node as visited and enqueue it
  int start = s;
  int distance = 0;
  int counter = 0;
  visited[s] = true;
  queue.push(s);
  bool endFlag = false;
  int shortestLength = V;

  if (start == target) {
    shortestLength = 0;
    return;
  }

  std::cout << "__________ BFS ____________" << std::endl;
  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop();

    // If we found our target destination, return distance
    if (s == target) {
      std::cout << std::endl;
      std::cout << "Target destination found!" << std::endl;
      std::cout << "start = " << start << std::endl;
      std::cout << "curPointer s = " << s << std::endl;
      std::cout << "target = " << target << std::endl;
      endFlag = true;
    }

    // Get all adjacent vertices of the dequeued
    // vertex s. If a adjacent has not been visited,
    // then mark it visited and enqueue it

    for (auto x : adjBFS[s]) {
      if (!visited[int(x)]) {
        visited[int(x)] = true;
        queue.push(x);

        // Print paths for debugging
        lengths[int(x)] = lengths[int(s)] + 1;
        prevCells[int(x)] = s;

        std::cout << "length at node " << x << " = " << lengths[int(x)] << std::endl;
      }
    }
  }

  int prev = prevCells[target];
  int cur = target;
  while (prev != -1) {
    distance++;
    cur = prev;
    prev = prevCells[cur];
    path.push_back(cur);
  }

  std::cout << "\n Shortest Path backtrack: \n " << target;
  for (auto x : path) {
    std::cout << " -> " << x;
  }

  std::cout << "\n Length = " << distance << std::endl;
}