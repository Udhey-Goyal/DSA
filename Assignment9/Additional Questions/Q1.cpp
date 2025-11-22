// Graph Traversal Count
// Given an undirected graph G(V, E) with V representing the number of vertices numbered from 0 to V-1 and E representing the number of edges, what is the task? Each edge connects two vertices u and v.
// Task: Determine the number of connected components in the graph.

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<int> &vis)
{
  vis[u] = 1;
  for (int v : g[u])
  {
    if (!vis[v])
      dfs(v, g, vis);
  }
}

int main()
{
  int V, E;
  cin >> V >> E;

  vector<vector<int>> g(V);
  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> vis(V, 0);
  int count = 0;

  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      count++;
      dfs(i, g, vis);
    }
  }

  cout << count;
  return 0;
}
