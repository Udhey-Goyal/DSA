// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Time Complexity: O(Cn * n) Catalan number
// Space Complexity: O(Cn * n)

#include <iostream>
#include <vector>
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

vector<Node *> solve(int l, int r)
{
  if (l > r)
    return {NULL};
  vector<Node *> res;
  for (int i = l; i <= r; i++)
  {
    vector<Node *> L = solve(l, i - 1);
    vector<Node *> R = solve(i + 1, r);
    for (auto a : L)
    {
      for (auto b : R)
      {
        Node *root = new Node(i);
        root->left = a;
        root->right = b;
        res.push_back(root);
      }
    }
  }
  return res;
}

void print(Node *root)
{
  if (!root)
  {
    cout << -1 << " ";
    return;
  }
  cout << root->data << " ";
  print(root->left);
  print(root->right);
}

int main()
{
  int n;
  cin >> n;

  vector<Node *> ans = solve(1, n);
  for (auto t : ans)
  {
    print(t);
    cout << "\n";
  }
  return 0;
}