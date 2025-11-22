// Dijkstra's Shortest Path Algorithm

// Time Complexity: O((V + E) log V)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int s;
  cin >> s;

  vector<int> dist(n, 1e9);
  dist[s] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});

  while (!pq.empty())
  {
    auto t = pq.top();
    pq.pop();
    int d = t.first, u = t.second;
    if (d != dist[u])
      continue;

    for (auto &p : g[u])
    {
      int v = p.first, w = p.second;
      if (dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  for (int x : dist)
    cout << x << " ";
  return 0;
}