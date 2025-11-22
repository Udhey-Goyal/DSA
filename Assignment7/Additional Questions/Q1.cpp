// Majority Element
// Given an array nums of size n, return the majority element. The majority element is the element that
// appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> &a)
{
  int cnt = 0, ele = 0;
  for (int x : a)
  {
    if (cnt == 0)
      ele = x;
    cnt += (x == ele) ? 1 : -1;
  }
  return ele;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << majorityElement(a);
  return 0;
}
