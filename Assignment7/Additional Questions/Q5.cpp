// Maximum Icecream bars
// It is a sweltering summer day, and a boy wants to buy some ice cream bars. At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins to spend, and he wants to buy as many ice cream bars as possible.

// Time Complexity: O(n + m)
// Space Complexity: O(m)
// m = max cost value

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, coins;
  cin >> n >> coins;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] > mx)
      mx = a[i];
  }

  vector<int> cnt(mx + 1, 0);
  for (int x : a)
    cnt[x]++;

  int ans = 0;
  for (int cost = 1; cost <= mx; cost++)
  {
    while (cnt[cost] > 0 && coins >= cost)
    {
      coins -= cost;
      ans++;
      cnt[cost]--;
    }
    if (coins < cost)
      break;
  }

  cout << ans;
  return 0;
}