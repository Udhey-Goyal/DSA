// Given a Doubly linked list containing n nodes. The task is to reverse every group of k
// nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the
// end should be considered as a group and must be reversed.

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

Node *reverseK(Node *head, int k)
{
  if (!head)
    return NULL;
  Node *curr = head;
  Node *newHead = NULL;
  Node *next = NULL;
  int count = 0;
  while (curr && count < k)
  {
    next = curr->next;
    curr->next = curr->prev;
    curr->prev = next;
    newHead = curr;
    curr = next;
    count++;
  }
  if (next)
  {
    head->next = reverseK(next, k);
    if (head->next)
      head->next->prev = head;
  }
  return newHead;
}

void display(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

int main()
{
  Node *head = NULL;
  int n, x, k;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    insertLast(head, x);
  }
  cin >> k;
  head = reverseK(head, k);
  display(head);
}