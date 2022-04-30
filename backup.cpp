#include "main.h"
#include "Graph.h"

void addEdge(std::vector<int> adj[], std::string inputFile) {
  std::ifstream File(inputFile);
  std::string line;
  while(std::getline(File, line)) {
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

    // std::cout << "Start node: " << node1 << " " << std::endl;
    // std::cout << "End node: " << node2 << " " << std::endl;
    // std::cout << "\n";
  }
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(std::vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        std::cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            std::cout << " -> " << x;
        printf("\n");
    }
}


void BFS(std::vector<int> adj[], int s, int target, int V) {

    // Include data correction step


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

    // // Mark all the vertices as not visited
    // bool *visited = new bool[V];
    // for(int i = 0; i < V; i++)
    //     visited[i] = false;


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

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        // std::cout << s << " ";
        queue.pop();
        // distance++; /// ******

        // If we found our target destination, return distance
        if (s == target) {
          std::cout << std::endl;
          std::cout << "Target destination found!" << std::endl;
          std::cout << "Distance = " << distance - 1 << std::endl;
          std::cout << "start = " << start << std::endl;
          std::cout << "curPointer s = " << s << std::endl;
          std::cout << "target = " << target << std::endl;
          endFlag = true;
          // break;
          // vector to store the various answers 
        }

 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        // if (!endFlag) {
          for (auto x : adj[s]) {

              if (!visited[int(x)]) {
                visited[int(x)] = true;
                queue.push(x);

                // Print paths for debugging
                lengths[int(x)] = lengths[int(s)] + 1;
                prevCells[int(x)] = s;

                std::cout << "length at node " << x << " = "<< lengths[int(x)] << std::endl;
              }
          }
        // }
        // for (i = adj[s].begin(); i != adj[s].end(); ++i)
        // {
        //     if (!visited[*i])
        //     {
        //         visited[*i] = true;
        //         queue.push_back(*i);
        //     }
        // }
    }

    int prev = prevCells[target];
    int cur = target;
    while (prev != -1) {
      distance++;
      cur = prev;
      prev = prevCells[cur];
      path.push_back(cur);
    }

    // // Run through the lengths vector and find which had the shortest length
    // int counter;
    // for (int i = 0; i < V; i++) {
    //     // std::cout << "lengths = " << lengths[i] << std::endl;
    //     if (lengths[i] < shortestLength && lengths[i] > 0) {
    //         counter = i;
    //         shortestLength = lengths[i];
    //     }
    // }

    std::cout << "\n Shortest Path backtrack: \n " << target;
    for (auto x : path) {
        std::cout << " -> " << x;
    }

    std::cout << "\n Length = " << distance << std::endl;
    std::cout << "\n counter = " << counter << std::endl;


    // std::cout << "Distance (hopefully right) = " << shortestLength << std::endl;

    // Directions... to do later

}


int main() {
  int line_count = 0;
  std::ifstream File("dataset/cal.cedge.txt");
  std::string line;
  while(std::getline(File, line)) {
    line_count++;
  }

  std::vector<int> adjMat[21693]; // error when I use line_count fsr
  
  
  addEdge(adjMat, "dataset/cal.cedge.txt");

  printGraph(adjMat, 10); // printed only first ten lists

  int startNode = 5;
  int destinationNode = 252;
  BFS(adjMat, startNode, destinationNode, line_count);

  return 0;
}