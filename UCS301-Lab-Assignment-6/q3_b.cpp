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

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* newNode = new Node();
        newNode->data = x;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    if (head == NULL) {
        cout << "Size of CLL = 0";
        return 0;
    }

    int size = 0;
    Node* temp = head;

    do {
        size++;
        temp = temp->next;
    } while (temp != head);

    cout << "Size of CLL = " << size;
    return 0;
}
