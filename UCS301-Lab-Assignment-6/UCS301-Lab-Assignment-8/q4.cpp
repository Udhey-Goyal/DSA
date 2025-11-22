#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};


Node* Insert(Node* p, int key) {
    if (p == NULL) {
        Node* t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = Insert(p->lchild, key);
    else
        p->rchild = Insert(p->rchild, key);
    return p;
}

int prevValue = -1000000;

bool isBST(Node* p) {
    if (p == NULL) return true;

    if (!isBST(p->lchild))
        return false;

    if (p->data <= prevValue)
        return false;

    prevValue = p->data;

    return isBST(p->rchild);
}

int main() {
    Node* root = NULL;

    
    int a[] = {10, 5, 1, 7, 40, 50};
    for (int i = 0; i < 6; i++)
        root = Insert(root, a[i]);

    if (isBST(root))
        cout << "This is a BST";
    else
        cout << "Not a BST";

    return 0;
}
