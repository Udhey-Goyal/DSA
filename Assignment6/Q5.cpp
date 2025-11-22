// Write a program to check if a linked list is Circular Linked List or not.

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
  n->next = NULL;
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
  }
}

bool isCircular(Node *head)
{
  if (!head)
    return false;
  Node *t = head->next;
  while (t && t != head)
    t = t->next;
  return t == head;
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
  char c;
  cin >> c;
  if (c == 'Y')
  {
    Node *t = head;
    while (t->next)
      t = t->next;
    t->next = head;
  }
  cout << (isCircular(head) ? "True" : "False");
}