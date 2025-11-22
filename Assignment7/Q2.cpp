// A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
// every pass on the array, and place it at its correct position. The idea is to take also the maximum on
// every pass and place it at its correct position. So in every pass, we keep track of both maximum and
// minimum and array becomes sorted from both ends. Implement this logic.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void improvedSelection(int a[], int n)
{
  int left = 0, right = n - 1;
  while (left < right)
  {
    int mn = left, mx = right;
    for (int i = left; i <= right; i++)
    {
      if (a[i] < a[mn])
        mn = i;
      if (a[i] > a[mx])
        mx = i;
    }

    int t = a[left];
    a[left] = a[mn];
    a[mn] = t;

    if (mx == left)
      mx = mn;

    t = a[right];
    a[right] = a[mx];
    a[mx] = t;

    left++;
    right--;
  }
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  improvedSelection(a, n);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  return 0;
}
