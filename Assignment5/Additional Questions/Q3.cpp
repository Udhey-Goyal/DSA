// Given a linked list, remove the loop if it exists.

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

bool detectAndRemoveLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      slow = head;
      if (slow == fast)
      {
        while (fast->next != slow)
          fast = fast->next;
      }
      else
      {
        while (slow->next != fast->next)
        {
          slow = slow->next;
          fast = fast->next;
        }
      }
      fast->next = NULL;
      return true;
    }
  }
  return false;
}

void display(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data;
    if (temp->next)
      cout << "->";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  insertEnd(1);
  insertEnd(2);
  insertEnd(3);
  insertEnd(4);
  insertEnd(5);

  // create a loop for testing (5->3)
  head->next->next->next->next->next = head->next->next;

  if (detectAndRemoveLoop(head))
    cout << "Loop detected and removed" << endl;
  else
    cout << "No loop found" << endl;

  cout << "Linked List after removal: ";
  display(head);

  return 0;
}