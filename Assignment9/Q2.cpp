// Depth First Search (DFS)

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &g, vector<int> &vis)
{
  vis[u] = 1;
  cout << u << " ";
  for (int v : g[u])
  {
    if (!vis[v])
      dfsUtil(v, g, vis);
  }
}

void dfs(int n, vector<vector<int>> &g, int s)
{
  vector<int> vis(n, 0);
  dfsUtil(s, g, vis);
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> g(n);
  for (int i = 0; i < e; i++)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int start;
  cin >> start;
  dfs(n, g, start);
  return 0;
}