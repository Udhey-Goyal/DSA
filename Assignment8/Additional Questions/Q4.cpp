// There are different ways to look at a binary tree. The right view of a binary tree contains the set of nodes that will be visible if you look at the binary tree from the right side. Given the root node of a binary tree, return an array containing the node elements in the right view, from top to bottom.

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

vector<int> rightView(Node *root)
{
  vector<int> r;
  if (!root)
    return r;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int s = q.size();
    for (int i = 0; i < s; i++)
    {
      Node *t = q.front();
      q.pop();
      if (i == s - 1)
        r.push_back(t->data);
      if (t->left)
        q.push(t->left);
      if (t->right)
        q.push(t->right);
    }
  }
  return r;
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
    vector<int> ans = rightView(root);

    for (int x : ans)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}