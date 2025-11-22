// Top K Frequent in Array
// Given a non-empty integer array arr[ ] of size n, find the top k elements which have the highest frequency in the array. Note: If two numbers have the same frequencies, then the larger number should be given more preference.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> topK(vector<int> &a, int k)
{
  map<int, int> f;
  for (int x : a)
    f[x]++;

  vector<pair<int, int>> v;
  for (auto &p : f)
    v.push_back({p.first, p.second});

  sort(v.begin(), v.end(), [](auto &x, auto &y)
       {
        if(x.second == y.second) return x.first > y.first;
        return x.second > y.second; });

  vector<int> ans;
  for (int i = 0; i < k; i++)
    ans.push_back(v[i].first);
  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> r = topK(a, k);
  for (int x : r)
    cout << x << " ";
  return 0;
}