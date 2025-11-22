// Write a program for binary search tree (BST) having functions for the following operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of

// Time Complexity: Insert/Delete/Search O(log n) avg, O(n) worst
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
  else if (x > root->data)
    root->right = insertNode(root->right, x);
  return root;
}

Node *getMin(Node *root)
{
  while (root && root->left)
    root = root->left;
  return root;
}

Node *deleteNode(Node *root, int x)
{
  if (!root)
    return root;
  if (x < root->data)
    root->left = deleteNode(root->left, x);
  else if (x > root->data)
    root->right = deleteNode(root->right, x);
  else
  {
    if (!root->left)
    {
      Node *t = root->right;
      delete root;
      return t;
    }
    if (!root->right)
    {
      Node *t = root->left;
      delete root;
      return t;
    }
    Node *t = getMin(root->right);
    root->data = t->data;
    root->right = deleteNode(root->right, t->data);
  }
  return root;
}

int maxDepth(Node *root)
{
  if (!root)
    return 0;
  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  return 1 + (l > r ? l : r);
}

int minDepth(Node *root)
{
  if (!root)
    return 0;
  int l = minDepth(root->left);
  int r = minDepth(root->right);
  if (!root->left)
    return 1 + r;
  if (!root->right)
    return 1 + l;
  return 1 + (l < r ? l : r);
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

  int del;
  cin >> del;
  root = deleteNode(root, del);

  cout << maxDepth(root) << "\n";
  cout << minDepth(root);

  return 0;
}