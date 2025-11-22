// Sort even-placed in increasing and odd-placed in decreasing order
// We are given an array of n distinct numbers. The task is to sort all even-placed numbers in increasing and odd-placed numbers in decreasing order. The modified array should contain all sorted even- placed numbers followed by reverse sorted odd-placed numbers.
// Note that the first element is considered as even placed because of its index 0.

// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), even, odd;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i % 2 == 0)
      even.push_back(a[i]);
    else
      odd.push_back(a[i]);
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end(), greater<int>());

  vector<int> ans;
  for (int x : even)
    ans.push_back(x);
  for (int x : odd)
    ans.push_back(x);

  for (int x : ans)
    cout << x << " ";
  return 0;
}