// Minimum Spanning Tree (Kruskal and Prim)

// Time Complexity: Kruskal O(E log E), Prim O(E log V)
// Space Complexity: O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct DSU
{
  vector<int> p, r;
  DSU(int n)
  {
    p.resize(n);
    r.resize(n, 0);
    for (int i = 0; i < n; i++)
      p[i] = i;
  }
  int find(int x)
  {
    if (p[x] == x)
      return x;
    return p[x] = find(p[x]);
  }
  void unite(int a, int b)
  {
    a = find(a);
    b = find(b);
    if (a != b)
    {
      if (r[a] < r[b])
        swap(a, b);
      p[b] = a;
      if (r[a] == r[b])
        r[a]++;
    }
  }
};

int kruskal(int n, vector<vector<int>> &edges)
{
  sort(edges.begin(), edges.end(), [](auto &a, auto &b)
       { return a[2] < b[2]; });
  DSU d(n);
  int cost = 0;
  for (auto &e : edges)
  {
    int u = e[0], v = e[1], w = e[2];
    if (d.find(u) != d.find(v))
    {
      d.unite(u, v);
      cost += w;
    }
  }
  return cost;
}

int prim(int n, vector<vector<pair<int, int>>> &g)
{
  vector<int> vis(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  int cost = 0;
  while (!pq.empty())
  {
    auto x = pq.top();
    pq.pop();
    int w = x.first, u = x.second;
    if (vis[u])
      continue;
    vis[u] = 1;
    cost += w;
    for (auto &p : g[u])
    {
      if (!vis[p.first])
      {
        pq.push({p.second, p.first});
      }
    }
  }
  return cost;
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> edges;
  vector<vector<pair<int, int>>> g(n);

  for (int i = 0; i < e; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  cout << kruskal(n, edges) << "\n";
  cout << prim(n, g) << "\n";
  return 0;
}