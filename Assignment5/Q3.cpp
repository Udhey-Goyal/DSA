// Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *head = NULL;

void insertEnd(int val)
{
  Node *newNode = new Node{val, NULL};
  if (!head)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
}

int findMiddle()
{
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}

int main()
{
  insertEnd(1);
  insertEnd(2);
  insertEnd(3);
  insertEnd(4);
  insertEnd(5);

  cout << "Middle: " << findMiddle() << endl;
  return 0;
}