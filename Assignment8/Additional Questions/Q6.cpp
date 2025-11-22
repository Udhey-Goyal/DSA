// Given in-order and post-order traversals, write a program to construct the Binary Tree.

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
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

Node *build(vector<int> &in, int is, int ie,
            vector<int> &post, int ps, int pe,
            unordered_map<int, int> &pos)
{

  if (is > ie || ps > pe)
    return NULL;

  Node *root = new Node(post[pe]);
  int k = pos[root->data];
  int left = k - is;

  root->left = build(in, is, k - 1, post, ps, ps + left - 1, pos);
  root->right = build(in, k + 1, ie, post, ps + left, pe - 1, pos);
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

int main()
{
  int n;
  cin >> n;

  vector<int> in(n), post(n);
  for (int i = 0; i < n; i++)
    cin >> in[i];
  for (int i = 0; i < n; i++)
    cin >> post[i];

  unordered_map<int, int> pos;
  for (int i = 0; i < n; i++)
    pos[in[i]] = i;

  Node *root = build(in, 0, n - 1, post, 0, n - 1, pos);

  preorder(root);
  return 0;
}