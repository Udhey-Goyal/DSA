#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front=NULL, *rear=NULL;

void enqueue(int x){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(front == NULL)
        front = rear = t;
    else{
        rear->next = t;
        rear = t;
    }
}

int dequeue(){
    if(front == NULL) return -1;
    int x = front->data;
    struct Node *t = front;
    front = front->next;
    free(t);
    return x;
}

int isEmpty(){
    return front == NULL;
}

void BFS(int G[][20], int start, int n){
    int visited[20] = {0};
    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);

    while(!isEmpty()){
        int u = dequeue();
        for(int v = 0; v < n; v++){
            if(G[u][v] == 1 && visited[v] == 0){
                printf("%d ", v);
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int G[20][20];
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    printf("BFS Traversal :");
    BFS(G, 0, n);
    return 0;
}
