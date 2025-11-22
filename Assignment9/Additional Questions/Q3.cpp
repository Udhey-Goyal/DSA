// Network Delay Time
// You are given a directed weighted graph G(V, E) and an array times[] where times[i] = (u, v, w) represents an edge from node u to node v with weight w.
// Task: Given a starting node K, find how long it takes for all nodes to receive the signal.
// If some nodes cannot be reached, return -1.

// Time Complexity: O(E log V)
// Space Complexity: O(V + E)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int N, E, K;
  cin >> N >> E >> K;

  vector<vector<pair<int, int>>> g(N + 1);
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  vector<int> dist(N + 1, 1e9);
  dist[K] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, K});

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

  int ans = 0;
  for (int i = 1; i <= N; i++)
  {
    if (dist[i] == 1e9)
    {
      cout << -1;
      return 0;
    }
    ans = max(ans, dist[i]);
  }

  cout << ans;
  return 0;
}
