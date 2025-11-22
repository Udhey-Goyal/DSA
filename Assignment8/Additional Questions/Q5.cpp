// Given preorder and in-order traversals, write a program to construct the Binary Tree.

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

Node *buildTree(vector<int> &pre, int ps, int pe,
                vector<int> &in, int is, int ie,
                unordered_map<int, int> &pos)
{
  if (ps > pe || is > ie)
    return NULL;
  Node *root = new Node(pre[ps]);
  int k = pos[root->data];
  int left = k - is;
  root->left = buildTree(pre, ps + 1, ps + left, in, is, k - 1, pos);
  root->right = buildTree(pre, ps + left + 1, pe, in, k + 1, ie, pos);
  return root;
}

void printPost(Node *root)
{
  if (!root)
    return;
  printPost(root->left);
  printPost(root->right);
  cout << root->data << " ";
}

int main()
{
  int n;
  cin >> n;

  vector<int> pre(n), in(n);
  for (int i = 0; i < n; i++)
    cin >> pre[i];
  for (int i = 0; i < n; i++)
    cin >> in[i];

  unordered_map<int, int> pos;
  for (int i = 0; i < n; i++)
    pos[in[i]] = i;

  Node *root = buildTree(pre, 0, n - 1, in, 0, n - 1, pos);

  printPost(root);
  return 0;
}