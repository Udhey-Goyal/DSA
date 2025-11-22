// Given a Doubly linked list and Circular singly linked list containing N nodes, the task is
// to remove all the nodes from each list which contains elements whose parity is even.

// Time Complexity: O(n * logM)   [M = max node value]
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int parityCount(int x)
{
  int c = 0;
  while (x)
  {
    if (x & 1)
      c++;
    x >>= 1;
  }
  return c;
}

struct DNode
{
  int data;
  DNode *prev;
  DNode *next;
};

DNode *createDNode(int d)
{
  DNode *n = new DNode;
  n->data = d;
  n->prev = n->next = NULL;
  return n;
}

void insertLastDLL(DNode *&head, int d)
{
  DNode *n = createDNode(d);
  if (!head)
    head = n;
  else
  {
    DNode *t = head;
    while (t->next)
      t = t->next;
    t->next = n;
    n->prev = t;
  }
}

void removeEvenParityDLL(DNode *&head)
{
  DNode *t = head;
  while (t)
  {
    DNode *nxt = t->next;
    if (parityCount(t->data) % 2 == 0)
    {
      if (t == head)
        head = t->next;
      if (t->prev)
        t->prev->next = t->next;
      if (t->next)
        t->next->prev = t->prev;
      delete t;
    }
    t = nxt;
  }
}

void displayDLL(DNode *head)
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

void removeEvenParityCLL(CNode *&head)
{
  if (!head)
    return;
  CNode *curr = head;
  CNode *prev = NULL;
  do
  {
    CNode *nxt = curr->next;
    if (parityCount(curr->data) % 2 == 0)
    {
      if (curr == head)
      {
        CNode *t = head;
        while (t->next != head)
          t = t->next;
        if (t == head)
        {
          delete head;
          head = NULL;
          return;
        }
        t->next = head->next;
        delete head;
        head = t->next;
        curr = head;
        prev = NULL;
        continue;
      }
      else
        prev->next = curr->next;
      delete curr;
    }
    else
      prev = curr;
    curr = nxt;
  } while (curr != head);
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
  DNode *dll = NULL;
  CNode *cll = NULL;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    insertLastDLL(dll, x);
    insertLastCLL(cll, x);
  }
  removeEvenParityDLL(dll);
  removeEvenParityCLL(cll);
  displayDLL(dll);
  displayCLL(cll);
}