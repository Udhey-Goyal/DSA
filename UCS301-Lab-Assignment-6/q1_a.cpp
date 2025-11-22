#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    int choice, val, key;

    while (true) {
        cout << "\nCircular Linked List Menu\n";
        cout << "1.Insert at Beginning\n2.Insert at End\n3.Insert Before a Value\n4.Insert After a Value\n";
        cout << "5.Delete a Value\n6.Search\n7.Display\n8.Exit\n";
        cin >> choice;

        if (choice == 1) {  // insert at beginning
            cout << "Enter value: "; cin >> val;
            Node* newNode = new Node();
            newNode->data = val;

            if (head == NULL) {
                head = newNode;
                newNode->next = head;
            }
            else {
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                newNode->next = head;
                temp->next = newNode;
                head = newNode;
            }
        }

        else if (choice == 2) { // insert at end
            cout << "Enter value: "; cin >> val;
            Node* newNode = new Node();
            newNode->data = val;

            if (head == NULL) {
                head = newNode;
                newNode->next = head;
            }
            else {
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                temp->next = newNode;
                newNode->next = head;
            }
        }

        else if (choice == 3 || choice == 4) { // before/after
            cout << "Enter key value: "; cin >> key;
            cout << "Enter new value: "; cin >> val;
            Node* newNode = new Node();
            newNode->data = val;

            if (head == NULL) { cout << "List empty\n"; continue; }

            Node* temp = head;
            Node* prev = NULL;

            do {
                if (temp->data == key) break;
                prev = temp;
                temp = temp->next;
            } while (temp != head);

            if (temp->data != key) {
                cout << "Key not found\n";
                continue;
            }

            if (choice == 3) { // INSERT BEFORE key
                if (temp == head) {
                    // insert before head
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    newNode->next = head;
                    last->next = newNode;
                    head = newNode;
                }
                else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
            else {  // INSERT AFTER key
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        else if (choice == 5) { // delete
            cout << "Enter value to delete: "; cin >> key;

            if (head == NULL) { cout << "List empty\n"; continue; }

            Node* temp = head;
            Node* prev = NULL;

            // delete head case
            if (head->data == key) {
                // only one node
                if (head->next == head) {
                    delete head;
                    head = NULL;
                }
                else {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = head->next;
                    Node* del = head;
                    head = head->next;
                    delete del;
                }
            }
            else {
                do {
                    if (temp->data == key) break;
                    prev = temp;
                    temp = temp->next;
                } while (temp != head);

                if (temp->data != key) {
                    cout << "Value not found\n";
                }
                else {
                    prev->next = temp->next;
                    delete temp;
                }
            }
        }

        else if (choice == 6) { // search
            cout << "Enter value: "; cin >> key;
            if (head == NULL) { cout << "List empty\n"; continue; }

            Node* temp = head;
            int pos = 1;
            bool found = false;
            do {
                if (temp->data == key) {
                    cout << "Found at position " << pos << "\n";
                    found = true;
                    break;
                }
                temp = temp->next;
                pos++;
            } while (temp != head);

            if (!found) cout << "Not found\n";
        }

        else if (choice == 7) { // display
            if (head == NULL) { cout << "List empty\n"; continue; }
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }

        else if (choice == 8) break;

        else cout << "Invalid choice\n";
    }

    return 0;
}
