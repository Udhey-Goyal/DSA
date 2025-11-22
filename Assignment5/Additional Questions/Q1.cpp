// Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
// The lists may vary in length and have distinct nodes at the beginning, but from the point of
// intersection onward, they share the same sequence of nodes. The task is to identify the first
// common node where the two lists converge. If the two linked lists have no intersection at all,
// return null.
// Input: listA = [4,1,8,5], listB = [5,6,1,8,5]
// Output: Intersected at 8

// Time Complexity: O(m+n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *getIntersectionNode(Node *headA, Node *headB)
{
  if (!headA || !headB)
    return NULL;
  Node *a = headA;
  Node *b = headB;
  while (a != b)
  {
    a = a ? a->next : headB;
    b = b ? b->next : headA;
  }
  return a;
}

int main()
{
  Node *common1 = new Node{8, NULL};
  Node *common2 = new Node{5, NULL};
  common1->next = common2;

  Node *listA = new Node{4, NULL};
  listA->next = new Node{1, common1};

  Node *listB = new Node{5, NULL};
  listB->next = new Node{6, NULL};
  listB->next->next = new Node{1, common1};

  Node *intersect = getIntersectionNode(listA, listB);
  if (intersect)
    cout << "Intersected at " << intersect->data << endl;
  else
    cout << "No intersection" << endl;

  return 0;
}
