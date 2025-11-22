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

    int choice, val, key;

    while (true) {
        cout << "\n Doubly Linked List Menu \n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert Before a Value\n4. Insert After a Value\n";
        cout << "5. Delete a Value\n6. Search\n7. Display\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // INSERT AT BEGINNING
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;

            Node* newNode = new Node();
            newNode->data = val;
            newNode->prev = NULL;
            newNode->next = head;

            if (head != NULL) head->prev = newNode;
            else tail = newNode;  // list was empty

            head = newNode;
        }

        // INSERT AT END
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;

            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = NULL;
            newNode->prev = tail;

            if (tail != NULL) tail->next = newNode;
            else head = newNode;

            tail = newNode;
        }

        // INSERT BEFORE or AFTER
        else if (choice == 3 || choice == 4) {
            cout << "Enter key value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;

            if (head == NULL) {
                cout << "List empty\n";
                continue;
            }

            Node* temp = head;
            while (temp != NULL && temp->data != key)
                temp = temp->next;

            if (temp == NULL) {
                cout << "Key not found\n";
                continue;
            }

            Node* newNode = new Node();
            newNode->data = val;

            // INSERT BEFORE
            if (choice == 3) {
                newNode->next = temp;
                newNode->prev = temp->prev;

                if (temp->prev != NULL)
                    temp->prev->next = newNode;
                else
                    head = newNode;

                temp->prev = newNode;
            }

            // INSERT AFTER
            else {
                newNode->prev = temp;
                newNode->next = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = newNode;
                else
                    tail = newNode;

                temp->next = newNode;
            }
        }

        // DELETE A VALUE
        else if (choice == 5) {
            cout << "Enter value to delete: ";
            cin >> key;

            if (head == NULL) {
                cout << "List empty\n";
                continue;
            }

            Node* temp = head;
            while (temp != NULL && temp->data != key)
                temp = temp->next;

            if (temp == NULL) {
                cout << "Value not found\n";
                continue;
            }

            // CASE 1: delete head
            if (temp == head) {
                head = head->next;
                if (head != NULL) head->prev = NULL;
                else tail = NULL;  // list empty now
            }

            // CASE 2: delete tail
            else if (temp == tail) {
                tail = tail->prev;
                tail->next = NULL;
            }

            // CASE 3: delete middle node
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Node deleted\n";
        }

        // SEARCH
        else if (choice == 6) {
            cout << "Enter value to search: ";
            cin >> key;

            Node* temp = head;
            int pos = 1;
            bool found = false;

            while (temp != NULL) {
                if (temp->data == key) {
                    cout << "Found at position " << pos << "\n";
                    found = true;
                    break;
                }
                temp = temp->next;
                pos++;
            }

            if (!found) cout << "Not found\n";
        }

        // DISPLAY
        else if (choice == 7) {
            if (head == NULL) {
                cout << "List empty\n";
                continue;
            }

            cout << "List: ";
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        else if (choice == 8) break;

        else cout << "Invalid choice\n";
    }

    return 0;
}
