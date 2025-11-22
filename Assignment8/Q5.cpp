// Implement Heapsort (Increasing/Decreasing order).

// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
  int mx = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && a[l] > a[mx])
    mx = l;
  if (r < n && a[r] > a[mx])
    mx = r;
  if (mx != i)
  {
    int t = a[i];
    a[i] = a[mx];
    a[mx] = t;
    heapify(a, n, mx);
  }
}

void heapSortInc(int a[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);
  for (int i = n - 1; i >= 0; i--)
  {
    int t = a[0];
    a[0] = a[i];
    a[i] = t;
    heapify(a, i, 0);
  }
}

void heapSortDec(int a[], int n)
{
  heapSortInc(a, n);
  int l = 0, r = n - 1;
  while (l < r)
  {
    int t = a[l];
    a[l] = a[r];
    a[r] = t;
    l++;
    r--;
  }
}

int main()
{
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[i] = a[i];
  }

  heapSortInc(a, n);
  heapSortDec(b, n);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << "\n";
  for (int i = 0; i < n; i++)
    cout << b[i] << " ";

  return 0;
}