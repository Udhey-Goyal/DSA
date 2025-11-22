// Given the root of a binary tree, return the sum of all left leaves. A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
#include <vector>
#include <queue>
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

Node *build(vector<int> &a)
{
  if (a.empty() || a[0] == -1)
    return NULL;
  Node *root = new Node(a[0]);
  queue<Node *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < a.size())
  {
    Node *cur = q.front();
    q.pop();
    if (a[i] != -1)
    {
      cur->left = new Node(a[i]);
      q.push(cur->left);
    }
    i++;
    if (i >= a.size())
      break;
    if (a[i] != -1)
    {
      cur->right = new Node(a[i]);
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

int sumLeft(Node *root, bool isLeft)
{
  if (!root)
    return 0;
  if (!root->left && !root->right)
  {
    if (isLeft)
      return root->data;
    return 0;
  }
  return sumLeft(root->left, true) + sumLeft(root->right, false);
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  Node *root = build(a);
  cout << sumLeft(root, false);
  return 0;
}
