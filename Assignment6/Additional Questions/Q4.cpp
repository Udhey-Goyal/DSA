// Given a doubly linked list having exactly one of the node pointing to a random node in the
// list, the task is to correct this random pointer in the doubly linked list, such that it points to
// the expected node.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
  Node *random;
};

Node *createNode(int d)
{
  Node *n = new Node;
  n->data = d;
  n->prev = n->next = n->random = NULL;
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

void correctRandomPointers(Node *head)
{
  Node *t = head;
  while (t)
  {
    if (t->random && t->random->data != t->data + 1)
    {
      Node *r = head;
      while (r && r->data != t->data + 1)
        r = r->next;
      t->random = r;
    }
    t = t->next;
  }
}

void display(Node *head)
{
  Node *t = head;
  while (t)
  {
    cout << t->data << "(";
    if (t->random)
      cout << t->random->data;
    else
      cout << "NULL";
    cout << ") ";
    t = t->next;
  }
  cout << "\n";
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
  Node *t = head;
  while (t && t->next)
  {
    t->random = t->next->next;
    t = t->next;
  }
  correctRandomPointers(head);
  display(head);
}