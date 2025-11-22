// Given a linked list, and an integer k, rotate the list to the left by k positions and return
// the updated head.

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

Node *rotateLeft(Node *head, int k)
{
  if (!head || k == 0)
    return head;
  Node *temp = head;
  int n = 1;
  while (temp->next)
  {
    temp = temp->next;
    n++;
  }
  k = k % n;
  if (k == 0)
    return head;
  temp->next = head;
  Node *newTail = head;
  for (int i = 1; i < k; i++)
    newTail = newTail->next;
  Node *newHead = newTail->next;
  newTail->next = NULL;
  return newHead;
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
  for (int i = 1; i <= 6; i++)
    insertEnd(i);

  cout << "Original List: ";
  display(head);

  int k = 2;
  head = rotateLeft(head, k);

  cout << "After rotating left by " << k << ": ";
  display(head);

  return 0;
}