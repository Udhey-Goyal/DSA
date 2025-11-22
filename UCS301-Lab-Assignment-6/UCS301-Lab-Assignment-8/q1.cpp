#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

void Preorder(Node* p) {
    if (p != NULL) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(Node* p) {
    if (p != NULL) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Postorder(Node* p) {
    if (p != NULL) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int main() {
    
    Node* root = new Node{10, NULL, NULL};
    root->lchild = new Node{20, NULL, NULL};
    root->rchild = new Node{30, NULL, NULL};
    root->lchild->lchild = new Node{40, NULL, NULL};

    cout << "Preorder: ";
    Preorder(root);
    cout << "\n";

    cout << "Inorder: ";
    Inorder(root);
    cout << "\n";

    cout << "Postorder: ";
    Postorder(root);
    cout << "\n";

    return 0;
}
