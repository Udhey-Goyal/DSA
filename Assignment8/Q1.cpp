// Write program using functions for binary tree traversals: Pre-order, In-order and Postorder using a recursive approach.

// Time Complexity: O(n)
// Space Complexity: O(n)

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

void preorder(Node *root)
{
  if (!root)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root)
{
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root)
{
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main()
{
  Node *root = build();

  preorder(root);
  cout << "\n";
  inorder(root);
  cout << "\n";
  postorder(root);

  return 0;
}
