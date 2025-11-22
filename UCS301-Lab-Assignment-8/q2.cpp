#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
};

Node* RInsert(Node* p, int key) {
    if (p == NULL) {
        Node* t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);
    return p;
}


Node* Search(Node* p, int key) {
    while (p != NULL) {
        if (key == p->data)
            return p;
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}


Node* RSearch(Node* p, int key) {
    if (p == NULL) return NULL;
    if (key == p->data) return p;
    else if (key < p->data) return RSearch(p->lchild, key);
    else return RSearch(p->rchild, key);
}


int Max(Node* p) {
    if (p == NULL) return -1;
    while (p->rchild != NULL)
        p = p->rchild;
    return p->data;
}


int Min(Node* p) {
    if (p == NULL) return -1;
    while (p->lchild != NULL)
        p = p->lchild;
    return p->data;
}


Node* InorderSuccessor(Node* p) {
    p = p->rchild;
    while (p != NULL && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node* InorderPredecessor(Node* p) {
    p = p->lchild;
    while (p != NULL && p->rchild != NULL)
        p = p->rchild;
    return p;
}


int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = RInsert(root, a[i]);

    cout << "Max = " << Max(root) << endl;
    cout << "Min = " << Min(root) << endl;

    Node* f = Search(root, 40);
    if (f) cout << "Found 40 (Iterative)\n";
    f = RSearch(root, 40);
    if (f) cout << "Found 40 (Recursive)\n";

    Node* suc = InorderSuccessor(RSearch(root, 50));
    cout << "Successor of 50 = " << suc->data << endl;

    Node* pre = InorderPredecessor(RSearch(root, 50));
    cout << "Predecessor of 50 = " << pre->data << endl;

    return 0;
}
