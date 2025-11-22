// Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
// the given Queue elements can be arranged in increasing order in another Queue using a stack. The
// operation allowed are:
// 1. Push and pop elements from the stack
// 2. Pop (Or Dequeue) from the given Queue.
// 3. Push (Or Enqueue) in the another Queue.
// Input : Queue[] = { 5, 1, 2, 3, 4 }
// Output : Yes

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> &q)
{
  stack<int> st;
  int expected = 1;
  int n = q.size();

  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    if (front == expected)
    {
      expected++;
    }
    else
    {
      if (!st.empty() && st.top() < front)
      {
        return false;
      }
      st.push(front);
    }

    while (!st.empty() && st.top() == expected)
    {
      st.pop();
      expected++;
    }
  }

  return (expected - 1 == n && st.empty());
}

int main()
{
  queue<int> q;
  q.push(5);
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  if (checkSorted(q))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}