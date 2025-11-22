// Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
// operations allowed on queue are:
// 1. enqueue() : Adds an item to rear of queue.
// 2. dequeue() : Removes an item from front of queue.
// 3. isEmpty() : Checks if a queue is empty.
// Input: 11, 5, 4, 21
// Output: 4, 5, 11, 21
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <iostream>
#include <queue>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex)
{
  int min_index = -1, min_val = INT_MAX;
  int n = q.size();

  for (int i = 0; i < n; i++)
  {
    int curr = q.front();
    q.pop();

    if (curr <= min_val && i <= sortedIndex)
    {
      min_index = i;
      min_val = curr;
    }
    q.push(curr);
  }
  return min_index;
}

void insertMinToRear(queue<int> &q, int min_index)
{
  int n = q.size();
  int min_val;
  for (int i = 0; i < n; i++)
  {
    int curr = q.front();
    q.pop();
    if (i == min_index)
    {
      min_val = curr;
    }
    else
    {
      q.push(curr);
    }
  }
  q.push(min_val);
}

void sortQueue(queue<int> &q)
{
  for (int i = 1; i <= q.size(); i++)
  {
    int min_index = minIndex(q, q.size() - i);
    insertMinToRear(q, min_index);
  }
}

int main()
{
  queue<int> q;
  q.push(11);
  q.push(5);
  q.push(4);
  q.push(21);

  sortQueue(q);

  cout << "Sorted Queue: ";
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
  return 0;
}