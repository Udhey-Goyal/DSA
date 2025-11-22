// Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST

// Time Complexity: Search/Min/Max/O(log n) avg, O(n) worst
// Space Complexity: O(h) for recursion, O(1) for iterative

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

Node *searchRec(Node *root, int x)
{
  if (!root || root->data == x)
    return root;
  if (x < root->data)
    return searchRec(root->left, x);
  return searchRec(root->right, x);
}

Node *searchIter(Node *root, int x)
{
  while (root)
  {
    if (root->data == x)
      return root;
    if (x < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return NULL;
}

Node *getMin(Node *root)
{
  while (root && root->left)
    root = root->left;
  return root;
}

Node *getMax(Node *root)
{
  while (root && root->right)
    root = root->right;
  return root;
}

Node *successor(Node *root, int x)
{
  Node *s = NULL;
  while (root)
  {
    if (x < root->data)
    {
      s = root;
      root = root->left;
    }
    else
      root = root->right;
  }
  return s;
}

Node *predecessor(Node *root, int x)
{
  Node *p = NULL;
  while (root)
  {
    if (x > root->data)
    {
      p = root;
      root = root->right;
    }
    else
      root = root->left;
  }
  return p;
}

int main()
{
  int n;
  cin >> n;
  Node *root = NULL;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    root = insertNode(root, x);
  }

  int key;
  cin >> key;

  Node *r1 = searchRec(root, key);
  Node *r2 = searchIter(root, key);
  if (r1)
    cout << "Found\n";
  else
    cout << "Not Found\n";

  cout << getMax(root)->data << "\n";
  cout << getMin(root)->data << "\n";

  Node *s = successor(root, key);
  Node *p = predecessor(root, key);

  if (s)
    cout << s->data << "\n";
  else
    cout << -1 << "\n";
  if (p)
    cout << p->data << "\n";
  else
    cout << -1 << "\n";

  return 0;
}