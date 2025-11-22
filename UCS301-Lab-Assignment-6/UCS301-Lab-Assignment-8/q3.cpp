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


int Height(Node* p) {
    if (p == NULL) return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return (x > y ? x + 1 : y + 1);
}


Node* InorderPredecessor(Node* p) {
    p = p->lchild;
    while (p->rchild != NULL)
        p = p->rchild;
    return p;
}


Node* InorderSuccessor(Node* p) {
    p = p->rchild;
    while (p->lchild != NULL)
        p = p->lchild;
    return p;
}


Node* Delete(Node* p, int key) {
    if (p == NULL) return NULL;

    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        if (p->lchild == NULL && p->rchild == NULL) {
            delete p;
            return NULL;
        }

        if (Height(p->lchild) > Height(p->rchild)) {
            Node* q = InorderPredecessor(p);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            Node* q = InorderSuccessor(p);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}


int MaxDepth(Node* p) {
    if (p == NULL) return 0;
    int x = MaxDepth(p->lchild);
    int y = MaxDepth(p->rchild);
    return (x > y ? x + 1 : y + 1);
}


int MinDepth(Node* p) {
    if (p == NULL) return 0;
    int x = MinDepth(p->lchild);
    int y = MinDepth(p->rchild);
    return (x < y ? x + 1 : y + 1);
}


int main() {
    Node* root = NULL;

    int a[] = {50, 30, 20, 40, 70, 60, 80};
    for (int i = 0; i < 7; i++)
        root = RInsert(root, a[i]);

    cout << "Max Depth = " << MaxDepth(root) << endl;
    cout << "Min Depth = " << MinDepth(root) << endl;

    root = Delete(root, 20);
    root = Delete(root, 30);
    root = Delete(root, 50);

    cout << "Max Depth After Deletions = " << MaxDepth(root) << endl;

    return 0;
}
