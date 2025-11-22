// Write a program to merge two BSTs into a doubly-linked list in sorted order.

// Time Complexity: O(n + m)
// Space Complexity: O(h)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left, *right;
  Node(int v)
  {
    data = v;
    left = right = NULL;
  }
};

Node *insertNode(Node *root, int x)
{
  if (!root)
    return new Node(x);
  if (x < root->data)
    root->left = insertNode(root->left, x);
  else
    root->right = insertNode(root->right, x);
  return root;
}

void bstToDll(Node *root, Node *&head, Node *&prev)
{
  if (!root)
    return;
  bstToDll(root->left, head, prev);
  if (!head)
    head = root;
  else
  {
    prev->right = root;
    root->left = prev;
  }
  prev = root;
  bstToDll(root->right, head, prev);
}

Node *mergeDll(Node *a, Node *b)
{
  if (!a)
    return b;
  if (!b)
    return a;
  Node *head = NULL;
  Node *tail = NULL;

  while (a && b)
  {
    Node *x;
    if (a->data < b->data)
    {
      x = a;
      a = a->right;
    }
    else
    {
      x = b;
      b = b->right;
    }
    if (!head)
    {
      head = tail = x;
    }
    else
    {
      tail->right = x;
      x->left = tail;
      tail = x;
    }
  }

  while (a)
  {
    tail->right = a;
    a->left = tail;
    tail = a;
    a = a->right;
  }

  while (b)
  {
    tail->right = b;
    b->left = tail;
    tail = b;
    b = b->right;
  }

  return head;
}

int main()
{
  int n1, n2;
  cin >> n1;
  Node *t1 = NULL;
  for (int i = 0; i < n1; i++)
  {
    int x;
    cin >> x;
    t1 = insertNode(t1, x);
  }

  cin >> n2;
  Node *t2 = NULL;
  for (int i = 0; i < n2; i++)
  {
    int x;
    cin >> x;
    t2 = insertNode(t2, x);
  }

  Node *h1 = NULL, *p1 = NULL, *h2 = NULL, *p2 = NULL;
  bstToDll(t1, h1, p1);
  bstToDll(t2, h2, p2);

  Node *head = mergeDll(h1, h2);

  while (head)
  {
    cout << head->data << " <-> ";
    head = head->right;
  }
  cout << "null";

  return 0;
}