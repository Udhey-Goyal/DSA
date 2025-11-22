#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string s;
    cout << "Enter string: ";
    cin >> s;

    // Create DLL
    for (int i = 0; i < s.length(); i++) {
        Node* newNode = new Node();
        newNode->data = s[i];
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL) tail->next = newNode;
        else head = newNode; // first node

        tail = newNode;
    }

    // Check palindrome using two pointers
    Node* left = head;
    Node* right = tail;

    bool isPalindrome = true;

    while (left != NULL && right != NULL && left != right && left->prev != right) {
        if (left->data != right->data) {
            isPalindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    if (isPalindrome) cout << "Palindrome";
    else cout << "Not Palindrome";

    return 0;
}
