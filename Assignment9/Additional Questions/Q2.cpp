// Shortest Path in Grid
// You are given a weighted grid size of m x n. Each cell contains a non-negative cost. Interpret the grid as a graph where each cell is a node and edges exist between adjacent horizontal/vertical cells with weights equal to the destination cell cost.
// Task: Determine the minimum total cost from (0,0) to (m-1,n-1) using Dijkstra.

// Time Complexity: O(m*n log(m*n))
// Space Complexity: O(m*n)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> dist(m, vector<int>(n, 1e9));
  dist[0][0] = a[0][0];

  priority_queue<
      pair<int, pair<int, int>>,
      vector<pair<int, pair<int, int>>>,
      greater<pair<int, pair<int, int>>>>
      pq;

  pq.push({a[0][0], {0, 0}});

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while (!pq.empty())
  {
    auto t = pq.top();
    pq.pop();

    int d = t.first;
    int x = t.second.first;
    int y = t.second.second;

    if (d != dist[x][y])
      continue;

    for (int k = 0; k < 4; k++)
    {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if (nx >= 0 && ny >= 0 && nx < m && ny < n)
      {
        int nd = d + a[nx][ny];
        if (nd < dist[nx][ny])
        {
          dist[nx][ny] = nd;
          pq.push({nd, {nx, ny}});
        }
      }
    }
  }

  cout << dist[m - 1][n - 1];
  return 0;
}
