// Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
// odd number of nodes in the given circular linked list then out of the resulting two halved
// lists, the first list should have one node more than the second list.

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

void splitCLL(Node *head, Node *&head1, Node *&head2)
{
  if (!head || head->next == head)
  {
    head1 = head;
    head2 = NULL;
    return;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast->next != head && fast->next->next != head)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (fast->next->next == head)
    fast = fast->next;
  head1 = head;
  if (head->next != head)
    head2 = slow->next;
  fast->next = slow->next;
  slow->next = head;
}

void display(Node *head)
{
  if (!head)
    return;
  Node *t = head;
  do
  {
    cout << t->data << " ";
    t = t->next;
  } while (t != head);
  cout << "\n";
}

int main()
{
  Node *head = NULL;
  Node *head1 = NULL;
  Node *head2 = NULL;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    insertLast(head, x);
  }
  splitCLL(head, head1, head2);
  display(head1);
  display(head2);
}
