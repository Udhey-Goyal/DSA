// Maximum Sum Combination
// You are given two integer arrays a[ ] and b[ ] of equal size. A sum combination is formed by adding one element from a[ ] and one from b[ ], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

// Time Complexity: O(n log n + k log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<int> maxCombinations(vector<int> &a, vector<int> &b, int k)
{
  int n = a.size();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  priority_queue<pair<int, pair<int, int>>> pq;
  set<pair<int, int>> used;

  pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
  used.insert({n - 1, n - 1});

  vector<int> ans;

  while (k--)
  {
    auto p = pq.top();
    pq.pop();
    ans.push_back(p.first);

    int i = p.second.first;
    int j = p.second.second;

    if (i - 1 >= 0 && !used.count({i - 1, j}))
    {
      pq.push({a[i - 1] + b[j], {i - 1, j}});
      used.insert({i - 1, j});
    }
    if (j - 1 >= 0 && !used.count({i, j - 1}))
    {
      pq.push({a[i] + b[j - 1], {i, j - 1}});
      used.insert({i, j - 1});
    }
  }

  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> r = maxCombinations(a, b, k);
  for (int x : r)
    cout << x << " ";
  return 0;
}