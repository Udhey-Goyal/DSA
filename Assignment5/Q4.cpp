// Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *head = NULL;

void insertEnd(int val)
{
  Node *newNode = new Node{val, NULL};
  if (!head)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
}

void reverseList()
{
  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;
  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

void display()
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main()
{
  insertEnd(1);
  insertEnd(2);
  insertEnd(3);
  insertEnd(4);

  cout << "Original List: ";
  display();

  reverseList();

  cout << "Reversed List: ";
  display();

  return 0;
}