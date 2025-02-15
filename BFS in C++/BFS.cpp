// #include <iostream>
// #include <list>

// using namespace std;

// class Graph {
//   int numVertices;
//   list<int>* adjLists;
//   bool* visited;

//    public:
//   Graph(int vertices);
//   void addEdge(int src, int dest);
//   void BFS(int startVertex);
// };

// Graph::Graph(int vertices) {
//   numVertices = vertices;
//   adjLists = new list<int>[vertices];
// }
// void Graph::addEdge(int src, int dest) {
//   adjLists[src].push_back(dest);
//   adjLists[dest].push_back(src);
// }

// void Graph::BFS(int startVertex) {
//   visited = new bool[numVertices];
//   for (int i = 0; i < numVertices; i++)
//     visited[i] = false;

//   list<int> queue;

//   visited[startVertex] = true;
//   queue.push_back(startVertex);

//   list<int>::iterator i;

//   while (!queue.empty()) {
//     int currVertex = queue.front();
//     cout << "Visited " << currVertex << " ";
//     queue.pop_front();

//     for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
//       int adjVertex = *i;
//       if (!visited[adjVertex]) {
//         visited[adjVertex] = true;
//         queue.push_back(adjVertex);
//       }
//     }
//   }
// }

// int main() {
//   Graph g(4);
//   g.addEdge(0, 1);
//   g.addEdge(0, 2);
//   g.addEdge(1, 2);
//   g.addEdge(2, 0);
//   g.addEdge(2, 3);
//   g.addEdge(3, 3);
//   g.BFS(2);
//   return 0;
// }
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph(int vertices);
    ~Graph(); // Destructor to free memory
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

// Constructor
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices]; // Allocate adjacency lists
    visited = new bool[vertices];       // Allocate visited array
}

// Destructor to free allocated memory
Graph::~Graph() {
    delete[] adjLists;
    delete[] visited;
}

// Function to add edges (undirected graph)
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

// BFS Implementation
void Graph::BFS(int startVertex) {
    // Reset visited array before each BFS call
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";

    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        cout << currVertex << " ";

        // Explore adjacent vertices
        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
    }
    cout << endl;
}

// Main function
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}
