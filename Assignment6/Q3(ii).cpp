// Write a program to find size of Circular Linked List.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *createNode(int d)
{
  Node *n = new Node;
  n->data = d;
  n->next = n;
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
    while (t->next != head)
      t = t->next;
    t->next = n;
    n->next = head;
  }
}

int sizeCLL(Node *head)
{
  if (!head)
    return 0;
  int c = 0;
  Node *t = head;
  do
  {
    c++;
    t = t->next;
  } while (t != head);
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
  cout << sizeCLL(head);
}