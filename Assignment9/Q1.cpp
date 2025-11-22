// Breadth First Search (BFS)

// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, vector<vector<int>> &g, int s)
{
  vector<int> vis(n, 0);
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    cout << u << " ";
    for (int v : g[u])
    {
      if (!vis[v])
      {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
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
  bfs(n, g, start);
  return 0;
}
