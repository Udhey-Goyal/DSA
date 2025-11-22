// Given a binary tree, return its maximum depth. The depth of a binary tree is the number of nodes from the root node to any of the leaf nodes. The maximum depth is the maximum of the depths across all the paths.

// Time Complexity: O(n)
// Space Complexity: O(n)

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

int depth(Node *root)
{
  if (!root)
    return 0;
  int l = depth(root->left);
  int r = depth(root->right);
  return 1 + (l > r ? l : r);
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Node *root = build(a);
    cout << depth(root) << "\n";
  }
  return 0;
}