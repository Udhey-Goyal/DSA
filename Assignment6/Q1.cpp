// Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *prev;
  Node *next;
};

Node *createNode(int d)
{
  Node *n = new Node;
  n->data = d;
  n->prev = n->next = NULL;
  return n;
}

void insertFirstDLL(Node *&head, int d)
{
  Node *n = createNode(d);
  if (!head)
    head = n;
  else
  {
    n->next = head;
    head->prev = n;
    head = n;
  }
}

void insertLastDLL(Node *&head, int d)
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

void insertAfterDLL(Node *head, int key, int d)
{
  Node *t = head;
  while (t && t->data != key)
    t = t->next;
  if (!t)
    return;
  Node *n = createNode(d);
  n->next = t->next;
  if (t->next)
    t->next->prev = n;
  t->next = n;
  n->prev = t;
}

void insertBeforeDLL(Node *&head, int key, int d)
{
  if (!head)
    return;
  if (head->data == key)
  {
    insertFirstDLL(head, d);
    return;
  }
  Node *t = head;
  while (t && t->data != key)
    t = t->next;
  if (!t)
    return;
  Node *n = createNode(d);
  n->prev = t->prev;
  n->next = t;
  t->prev->next = n;
  t->prev = n;
}

void deleteDLL(Node *&head, int key)
{
  if (!head)
    return;
  Node *t = head;
  while (t && t->data != key)
    t = t->next;
  if (!t)
    return;
  if (t == head)
    head = t->next;
  if (t->next)
    t->next->prev = t->prev;
  if (t->prev)
    t->prev->next = t->next;
  delete t;
}

bool searchDLL(Node *head, int key)
{
  while (head)
  {
    if (head->data == key)
      return true;
    head = head->next;
  }
  return false;
}

void displayDLL(Node *head)
{
  while (head)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

struct CNode
{
  int data;
  CNode *next;
};

CNode *createCNode(int d)
{
  CNode *n = new CNode;
  n->data = d;
  n->next = n;
  return n;
}

void insertFirstCLL(CNode *&head, int d)
{
  CNode *n = createCNode(d);
  if (!head)
    head = n;
  else
  {
    CNode *t = head;
    while (t->next != head)
      t = t->next;
    n->next = head;
    t->next = n;
    head = n;
  }
}

void insertLastCLL(CNode *&head, int d)
{
  CNode *n = createCNode(d);
  if (!head)
    head = n;
  else
  {
    CNode *t = head;
    while (t->next != head)
      t = t->next;
    t->next = n;
    n->next = head;
  }
}

void insertAfterCLL(CNode *head, int key, int d)
{
  if (!head)
    return;
  CNode *t = head;
  do
  {
    if (t->data == key)
    {
      CNode *n = createCNode(d);
      n->next = t->next;
      t->next = n;
      return;
    }
    t = t->next;
  } while (t != head);
}

void deleteCLL(CNode *&head, int key)
{
  if (!head)
    return;
  CNode *curr = head, *prev = NULL;
  do
  {
    if (curr->data == key)
    {
      if (curr == head)
      {
        CNode *t = head;
        while (t->next != head)
          t = t->next;
        if (t == head)
          head = NULL;
        else
        {
          t->next = head->next;
          head = head->next;
        }
      }
      else
        prev->next = curr->next;
      delete curr;
      return;
    }
    prev = curr;
    curr = curr->next;
  } while (curr != head);
}

bool searchCLL(CNode *head, int key)
{
  if (!head)
    return false;
  CNode *t = head;
  do
  {
    if (t->data == key)
      return true;
    t = t->next;
  } while (t != head);
  return false;
}

void displayCLL(CNode *head)
{
  if (!head)
    return;
  CNode *t = head;
  do
  {
    cout << t->data << " ";
    t = t->next;
  } while (t != head);
  cout << "\n";
}

int main()
{
  Node *dll = NULL;
  CNode *cll = NULL;
  int ch, x, y, type;
  while (true)
  {
    cout << "1.DLL  2.CLL  3.Exit: ";
    cin >> type;
    if (type == 3)
      break;
    cout << "1.InsertFirst 2.InsertLast 3.InsertAfter 4.InsertBefore 5.Delete 6.Search 7.Display 8.Exit: ";
    cin >> ch;
    if (type == 1)
    {
      if (ch == 1)
      {
        cin >> x;
        insertFirstDLL(dll, x);
      }
      else if (ch == 2)
      {
        cin >> x;
        insertLastDLL(dll, x);
      }
      else if (ch == 3)
      {
        cin >> y >> x;
        insertAfterDLL(dll, y, x);
      }
      else if (ch == 4)
      {
        cin >> y >> x;
        insertBeforeDLL(dll, y, x);
      }
      else if (ch == 5)
      {
        cin >> x;
        deleteDLL(dll, x);
      }
      else if (ch == 6)
      {
        cin >> x;
        cout << (searchDLL(dll, x) ? "Found\n" : "Not Found\n");
      }
      else if (ch == 7)
        displayDLL(dll);
      else
        break;
    }
    else
    {
      if (ch == 1)
      {
        cin >> x;
        insertFirstCLL(cll, x);
      }
      else if (ch == 2)
      {
        cin >> x;
        insertLastCLL(cll, x);
      }
      else if (ch == 3)
      {
        cin >> y >> x;
        insertAfterCLL(cll, y, x);
      }
      else if (ch == 5)
      {
        cin >> x;
        deleteCLL(cll, x);
      }
      else if (ch == 6)
      {
        cin >> x;
        cout << (searchCLL(cll, x) ? "Found\n" : "Not Found\n");
      }
      else if (ch == 7)
        displayCLL(cll);
      else
        break;
    }
  }
}
