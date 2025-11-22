#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
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
        newNode->prev = tail;
        newNode->next = NULL;

        if (tail != NULL) tail->next = newNode;
        else head = newNode;

        tail = newNode;
    }

    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }

    cout << "Size of DLL = " << size;
    return 0;
}
