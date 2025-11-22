// Given a 2D matrix, the task is to convert it into a doubly-linked list with four pointers
// that are next, previous, up, and down, each node of this list should be connected to its
// next, previous, up, and down nodes.

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
  Node *up;
  Node *down;
};

Node *createNode(int d)
{
  Node *n = new Node;
  n->data = d;
  n->next = n->prev = n->up = n->down = NULL;
  return n;
}

Node *convertToDLL(int mat[10][10], int n, int m)
{
  Node *head = NULL;
  Node *rowStart = NULL;
  Node *prevRowStart = NULL;
  Node *prev = NULL;

  for (int i = 0; i < n; i++)
  {
    prev = NULL;
    for (int j = 0; j < m; j++)
    {
      Node *newNode = createNode(mat[i][j]);
      if (!head)
        head = newNode;
      if (!rowStart)
        rowStart = newNode;
      if (prev)
      {
        prev->next = newNode;
        newNode->prev = prev;
      }
      if (prevRowStart)
      {
        Node *upNode = prevRowStart;
        for (int k = 0; k < j; k++)
          upNode = upNode->next;
        upNode->down = newNode;
        newNode->up = upNode;
      }
      prev = newNode;
    }
    prevRowStart = rowStart;
    rowStart = NULL;
  }
  return head;
}

void display(Node *head, int m)
{
  Node *row = head;
  while (row)
  {
    Node *col = row;
    int count = 0;
    while (col && count < m)
    {
      cout << col->data << " ";
      col = col->next;
      count++;
    }
    cout << "\n";
    row = row->down;
  }
}

int main()
{
  int n, m;
  int mat[10][10];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];
  Node *head = convertToDLL(mat, n, m);
  display(head, m);
}