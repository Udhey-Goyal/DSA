// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3.

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

int deleteOccurrences(int key)
{
  int count = 0;
  while (head && head->data == key)
  {
    Node *del = head;
    head = head->next;
    delete del;
    count++;
  }
  Node *temp = head;
  while (temp && temp->next)
  {
    if (temp->next->data == key)
    {
      Node *del = temp->next;
      temp->next = del->next;
      delete del;
      count++;
    }
    else
      temp = temp->next;
  }
  return count;
}

void display()
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
  insertEnd(1);
  insertEnd(2);
  insertEnd(1);
  insertEnd(3);
  insertEnd(1);

  int key = 1;
  int cnt = deleteOccurrences(key);
  cout << "Count: " << cnt << endl;
  cout << "Updated Linked List: ";
  display();
  return 0;
}