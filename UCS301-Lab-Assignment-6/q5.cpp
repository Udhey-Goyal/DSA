#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create a normal linear linked list first
    for (int i = 0; i < n; i++) {
        cin >> x;

        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    
     tail->next = head;  // make the list circular manually

    
    Node* slow = head;
    Node* fast = head;

    bool circular = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;             // move slow by 1
        fast = fast->next->next;       // move fast by 2

        if (slow == fast) {            // cycle found
            circular = true;
            break;
        }
    }

    if (circular)
        cout << "Circular Linked List";
    else
        cout << "NOT Circular";

    return 0;
}
