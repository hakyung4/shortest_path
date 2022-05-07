#include "Graph.h"

void Graph::addEdgeBFS(std::string inputFile) {
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

std::vector<std::vector<std::pair<int, float> > > Graph::addEdgeDijkstra(std::string inputFile, int V) {
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

void Graph::printPairedGraph(int V) {
  std::cout << "\n__________ Dijkstra's ____________\n"
            << std::endl;

  for (int v = 0; v < V; ++v) {
    // std::cout << "\nAdj Dijkstra's list of vertex " << v
    //           << "\nhead";

    for (auto x : adjDij[v]) {
      std::cout << " -> "
                << "(" << x.first << ", " << x.second << ")";
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

int Graph::BFS(int s, int target, int V) {
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
  }

  // std::cout << "\n__________ BFS ____________\n" << std::endl;
  while (!queue.empty()) {
    // Dequeue a vertex from queue and print it
    s = queue.front();
    queue.pop();

    // If we found our target destination, return distance
    if (s == target) {
      // std::cout << std::endl;
      // std::cout << "Target destination found!" << std::endl;
      // std::cout << "start = " << start << std::endl;
      // std::cout << "curPointer s = " << s << std::endl;
      // std::cout << "target = " << target << std::endl;
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

        // std::cout << "length at node " << x << " = "<< lengths[int(x)] << std::endl;
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

  std::cout << "\nBFS - Shortest Path backtrack: \n " << target;

  std::ofstream pathFile;
  pathFile.open("BFSpath.csv");
  pathFile << "BFS - Shortest Path backtrack:"
           << "\n";
  pathFile << target << "\n";
  for (auto x : path) {
    std::cout << " -> " << x;

    pathFile << x << "\n";
  }

  pathFile.close();
  std::cout << "\nNumber of nodes = " << distance << std::endl;
  return distance;
}

float Graph::Dijkstra(std::string inputFile, int &start, int &end) {
  int n = adjDij.size();
  std::vector<float> dist;
  int nodeCounter = 0;

  // Path vector to store directions
  std::vector<int> path;

  // Store prev cells in a vector, resize, set all to -1
  std::vector<int> prevCells;
  prevCells.resize(n, -1);

  // Initialize all source->vertex as infinite.
  for (int i = 0; i < n; i++) {
    // Define "infinity" as necessary by constraints.
    dist.push_back(1000000007);
  }

  // Create a priority queue.
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;

  // Add source to pq, where distance is 0.
  pq.push(std::make_pair(start, 0));
  // path.push_back(start);

  dist[start] = 0;
  bool flagDone = false;

  while (pq.empty() == false) {
    if (flagDone) {
      break;
    }
    // Get min distance vertex from pq. (Call it u.)
    int u = pq.top().first;
    pq.pop();

    int n = adjDij[u].size();

    // Visit all of u's friends. For each one (called v)
    for (int i = 0; i < n; i++) {
      if (flagDone) {
        break;
      }
      float v = adjDij[u][i].first;
      float wt = adjDij[u][i].second;

      // If the distance to v is shorter by going through u
      if (dist[v] > dist[u] + wt) {
        // Update the distance of v.
        dist[v] = dist[u] + wt;
        // Insert v into the pq.
        pq.push(std::make_pair(v, dist[v]));
        prevCells[v] = u;
      }

      if (v == end) {
        std::cout << "The distance from node " << start << " to node " << v << " is = " << dist[v] << std::endl;
        flagDone = true;
      }
    }
  }
  float distance = dist[end];

  int prev = prevCells[end];
  int cur = end;
  while (prev != -1) {
    cur = prev;
    prev = prevCells[cur];
    path.push_back(cur);
  }

  std::cout << "\nDijkstra - Shortest Path Backtrack: \n " << end;
  for (auto x : path) {
    std::cout << " -> " << x;
  }

  return distance;
}