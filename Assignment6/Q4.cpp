// Write a program to check if a doubly linked list of characters is palindrome or not.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  char data;
  Node *prev;
  Node *next;
};

Node *createNode(char d)
{
  Node *n = new Node;
  n->data = d;
  n->prev = n->next = NULL;
  return n;
}

void insertLast(Node *&head, char d)
{
  Node *n = createNode(d);
  if (!head)
    head = n;
  else
  {
    Node *t = head;
    while (t->next)
      t = t->next;
    t->next = n;
    n->prev = t;
  }
}

bool isPalindrome(Node *head)
{
  if (!head)
    return true;
  Node *left = head;
  Node *right = head;
  while (right->next)
    right = right->next;
  while (left != right && right->next != left)
  {
    if (left->data != right->data)
      return false;
    left = left->next;
    right = right->prev;
  }
  return true;
}

int main()
{
  Node *head = NULL;
  int n;
  char ch;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> ch;
    insertLast(head, ch);
  }
  cout << (isPalindrome(head) ? "True" : "False");
}