// Develop a menu driven program for the following operations on a Singly Linked
// List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.

// Time Complexity:
// Insertion at beginning: O(1)
// Insertion at end: O(n)
// Insertion before/after specific: O(n)
// Deletion at beginning: O(1)
// Deletion at end: O(n)
// Deletion of specific node: O(n)
// Search: O(n)
// Display: O(n)

// Space Complexity: O(n)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *head = NULL;

void insertBeginning(int val)
{
  Node *newNode = new Node{val, head};
  head = newNode;
}

void insertEnd(int val)
{
  Node *newNode = new Node{val, NULL};
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
}

void insertBefore(int val, int beforeVal)
{
  if (head == NULL)
    return;
  if (head->data == beforeVal)
  {
    insertBeginning(val);
    return;
  }
  Node *temp = head;
  while (temp->next && temp->next->data != beforeVal)
    temp = temp->next;
  if (temp->next)
  {
    Node *newNode = new Node{val, temp->next};
    temp->next = newNode;
  }
}

void insertAfter(int val, int afterVal)
{
  Node *temp = head;
  while (temp && temp->data != afterVal)
    temp = temp->next;
  if (temp)
  {
    Node *newNode = new Node{val, temp->next};
    temp->next = newNode;
  }
}

void deleteBeginning()
{
  if (head == NULL)
    return;
  Node *temp = head;
  head = head->next;
  delete temp;
}

void deleteEnd()
{
  if (head == NULL)
    return;
  if (head->next == NULL)
  {
    delete head;
    head = NULL;
    return;
  }
  Node *temp = head;
  while (temp->next->next)
    temp = temp->next;
  delete temp->next;
  temp->next = NULL;
}

void deleteSpecific(int val)
{
  if (head == NULL)
    return;
  if (head->data == val)
  {
    deleteBeginning();
    return;
  }
  Node *temp = head;
  while (temp->next && temp->next->data != val)
    temp = temp->next;
  if (temp->next)
  {
    Node *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
  }
}

void search(int val)
{
  Node *temp = head;
  int pos = 1;
  while (temp)
  {
    if (temp->data == val)
    {
      cout << "Found at position " << pos << endl;
      return;
    }
    temp = temp->next;
    pos++;
  }
  cout << "Not found" << endl;
}

void display()
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  int choice, val, key;
  while (true)
  {
    cout << "1.Insert Beginning\n2.Insert End\n3.Insert Before\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cin >> val;
      insertBeginning(val);
      break;
    case 2:
      cin >> val;
      insertEnd(val);
      break;
    case 3:
      cin >> val >> key;
      insertBefore(val, key);
      break;
    case 4:
      cin >> val >> key;
      insertAfter(val, key);
      break;
    case 5:
      deleteBeginning();
      break;
    case 6:
      deleteEnd();
      break;
    case 7:
      cin >> val;
      deleteSpecific(val);
      break;
    case 8:
      cin >> val;
      search(val);
      break;
    case 9:
      display();
      break;
    case 10:
      return 0;
    }
  }
}
