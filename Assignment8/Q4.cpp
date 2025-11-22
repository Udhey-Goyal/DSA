// Write a program to determine whether a given binary tree is a BST or not.

// Time Complexity: O(n)
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

Node *build()
{
  int x;
  cin >> x;
  if (x == -1)
    return NULL;
  Node *root = new Node(x);
  root->left = build();
  root->right = build();
  return root;
}

bool check(Node *root, long long mn, long long mx)
{
  if (!root)
    return true;
  if (root->data <= mn || root->data >= mx)
    return false;
  return check(root->left, mn, root->data) &&
         check(root->right, root->data, mx);
}

int main()
{
  Node *root = build();
  if (check(root, -1000000000000LL, 1000000000000LL))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}