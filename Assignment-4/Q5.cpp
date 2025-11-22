// Write a program to implement a stack using (a) Two queues and (b) One Queue.
// Time Complexity:
// push() - O(n)
// pop() - O(1)
// top() - O(1)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
  queue<int> q1, q2;

public:
  void push(int x)
  {
    q2.push(x);
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    swap(q1, q2);
  }

  void pop()
  {
    if (q1.empty())
    {
      cout << "Stack is Empty\n";
      return;
    }
    cout << "Popped: " << q1.front() << endl;
    q1.pop();
  }

  void top()
  {
    if (q1.empty())
    {
      cout << "Stack is Empty\n";
      return;
    }
    cout << "Top: " << q1.front() << endl;
  }

  bool empty()
  {
    return q1.empty();
  }
};

int main()
{
  StackTwoQueues st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.top();
  st.pop();
  st.top();
  return 0;
}