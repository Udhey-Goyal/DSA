// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q)
{
  int n = q.size();
  if (n % 2 != 0)
  {
    cout << "Queue has odd number of elements, cannot interleave\n";
    return;
  }

  int half = n / 2;
  queue<int> firstHalf;

  for (int i = 0; i < half; i++)
  {
    firstHalf.push(q.front());
    q.pop();
  }

  while (!firstHalf.empty())
  {
    q.push(firstHalf.front());
    firstHalf.pop();
    q.push(q.front());
    q.pop();
  }
}

int main()
{
  queue<int> q;
  int n, val;
  cout << "Enter number of elements (even): ";
  cin >> n;
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> val;
    q.push(val);
  }

  interleaveQueue(q);

  cout << "Interleaved Queue: ";
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}