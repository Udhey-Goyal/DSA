// Implement priority queues using heaps.

// Time Complexity: Insert O(log n), Delete O(log n), Get Max O(1)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

struct PQ
{
  vector<int> h;

  void heapifyDown(int i)
  {
    int n = h.size();
    int mx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && h[l] > h[mx])
      mx = l;
    if (r < n && h[r] > h[mx])
      mx = r;
    if (mx != i)
    {
      int t = h[i];
      h[i] = h[mx];
      h[mx] = t;
      heapifyDown(mx);
    }
  }

  void heapifyUp(int i)
  {
    while (i > 0)
    {
      int p = (i - 1) / 2;
      if (h[p] < h[i])
      {
        int t = h[p];
        h[p] = h[i];
        h[i] = t;
        i = p;
      }
      else
        break;
    }
  }

  void insertKey(int x)
  {
    h.push_back(x);
    heapifyUp(h.size() - 1);
  }

  int getMax()
  {
    if (h.empty())
      return -1;
    return h[0];
  }

  void deleteMax()
  {
    if (h.empty())
      return;
    h[0] = h.back();
    h.pop_back();
    heapifyDown(0);
  }

  void print()
  {
    for (int x : h)
      cout << x << " ";
    cout << "\n";
  }
};

int main()
{
  PQ pq;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    pq.insertKey(x);
  }

  pq.print();
  cout << pq.getMax() << "\n";
  pq.deleteMax();
  pq.print();

  return 0;
}