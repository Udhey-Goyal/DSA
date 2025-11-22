// Given two polynomial numbers represented by two linked lists. The task is
// to add these lists (meaning the coefficients with the same variable powers will be
// added).

// Time Complexity: O(max(m, n))
// Space Complexity: O(max(m, n))

#include <iostream>
using namespace std;

struct Node
{
  int coeff;
  int power;
  Node *next;
};

Node *insertEnd(Node *head, int coeff, int power)
{
  Node *newNode = new Node{coeff, power, NULL};
  if (!head)
    return newNode;
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
  return head;
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
  Node *result = NULL;
  Node *tail = NULL;

  while (poly1 && poly2)
  {
    Node *temp = NULL;
    if (poly1->power == poly2->power)
    {
      temp = new Node{poly1->coeff + poly2->coeff, poly1->power, NULL};
      poly1 = poly1->next;
      poly2 = poly2->next;
    }
    else if (poly1->power > poly2->power)
    {
      temp = new Node{poly1->coeff, poly1->power, NULL};
      poly1 = poly1->next;
    }
    else
    {
      temp = new Node{poly2->coeff, poly2->power, NULL};
      poly2 = poly2->next;
    }
    if (!result)
    {
      result = temp;
      tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }

  while (poly1)
  {
    tail->next = new Node{poly1->coeff, poly1->power, NULL};
    tail = tail->next;
    poly1 = poly1->next;
  }

  while (poly2)
  {
    tail->next = new Node{poly2->coeff, poly2->power, NULL};
    tail = tail->next;
    poly2 = poly2->next;
  }

  return result;
}

void display(Node *head)
{
  while (head)
  {
    cout << head->coeff << "x^" << head->power;
    if (head->next && head->next->coeff >= 0)
      cout << " + ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  Node *poly1 = NULL;
  Node *poly2 = NULL;

  poly1 = insertEnd(poly1, 5, 2);
  poly1 = insertEnd(poly1, 4, 1);
  poly1 = insertEnd(poly1, 2, 0);

  poly2 = insertEnd(poly2, 5, 1);
  poly2 = insertEnd(poly2, 5, 0);

  cout << "Polynomial 1: ";
  display(poly1);

  cout << "Polynomial 2: ";
  display(poly2);

  Node *sum = addPolynomials(poly1, poly2);
  cout << "Result: ";
  display(sum);

  return 0;
}