// Write a program to find size of Doubly Linked List.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
};

Node *createNode(int d)
{
  Node *n = new Node;
  n->data = d;
  n->prev = n->next = NULL;
  return n;
}

void insertLast(Node *&head, int d)
{
  Node *n = createNode(d);
  if (!head)
    head = n;
  else
  {
    Node *t = head;
    while (t->next)
      t = t->next;
    t->next = n;
    n->prev = t;
  }
}

int sizeDLL(Node *head)
{
  int c = 0;
  while (head)
  {
    c++;
    head = head->next;
  }
  return c;
}

int main()
{
  Node *head = NULL;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    insertLast(head, x);
  }
  cout << sizeDLL(head);
}