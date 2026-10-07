#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
  int vertices;
  vector<vector<int>> adj;

public:
  Graph(int v) {
    vertices = v;
    adj.resize(v);
  }

  // Add an undirected edge
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void BFS(int start) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      cout << u << " ";

      for (int v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    cout << endl;
  }

  void DFS(int u, vector<bool> &visited) {
    visited[u] = true;

    cout << u << " ";

    for (int v : adj[u]) {
      if (!visited[v]) {
        DFS(v, visited);
      }
    }
  }

  void DFS(int start) {
    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(start, visited);
    cout << endl;
  }
};

int main() {
  int vertices, edges;

  cout << "Enter number of vertices: ";
  cin >> vertices;

  Graph g(vertices);

  cout << "Enter number of edges: ";
  cin >> edges;

  cout << "Enter edges (u v):\n";

  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }

  int start;
  cout << "Enter starting vertex: ";
  cin >> start;

  g.BFS(start);
  g.DFS(start);

  return 0;
}
