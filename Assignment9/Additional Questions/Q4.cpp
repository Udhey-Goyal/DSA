// Number of Islands
// You are given a 2D grid of size M x N consisting of characters '0' and '1'. A group of connected '1's horizontally or vertically represents a piece of land, forming an island.
// Task: Count the total number of islands present in the grid using BFS/DFS.

// Time Complexity: O(M*N)
// Space Complexity: O(M*N)


#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>> &g, vector<vector<int>> &vis)
{
  int m = g.size(), n = g[0].size();
  vis[x][y] = 1;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  for (int k = 0; k < 4; k++)
  {
    int nx = x + dx[k], ny = y + dy[k];
    if (nx >= 0 && ny >= 0 && nx < m && ny < n && g[nx][ny] == 1 && !vis[nx][ny])
    {
      dfs(nx, ny, g, vis);
    }
  }
}

int main()
{
  int m, n;
  cin >> m >> n;

  vector<vector<int>> g(m, vector<int>(n));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> g[i][j];
    }
  }

  vector<vector<int>> vis(m, vector<int>(n, 0));
  int count = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (g[i][j] == 1 && !vis[i][j])
      {
        count++;
        dfs(i, j, g, vis);
      }
    }
  }

  cout << count;
  return 0;
}
