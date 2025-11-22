// Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
// nodes after multiples of k should be left as it is.
// Example 1:
// Input: Linked list: 1→2→3→4→5→6→7→8→9 ,K: 3
// Output: Result: 3→2→1→6→5→4→9→8→7
// Example 2
// Input: Linked list: 1→2→3→4→5→6→7→8 , K=3
// Output: Result: 3→2→1→6→5→4→7→8

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

Node *reverseKGroup(Node *head, int k)
{
  Node *curr = head;
  int count = 0;
  while (curr && count < k)
  {
    curr = curr->next;
    count++;
  }
  if (count < k)
    return head;

  curr = head;
  Node *prev = NULL;
  Node *next = NULL;
  count = 0;
  while (curr && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
  if (next)
    head->next = reverseKGroup(next, k);
  return prev;
}

void display(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data;
    if (temp->next)
      cout << "->";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  for (int i = 1; i <= 9; i++)
    insertEnd(i);
  int k = 3;
  cout << "Original List: ";
  display(head);
  head = reverseKGroup(head, k);
  cout << "Result: ";
  display(head);

  return 0;
}