#include <stdio.h>

void DFS(int G[][20], int u, int n){
    static int visited[20];
    if(visited[u] == 0){
        printf("%d ", u);
        visited[u] = 1;

        for(int v=0; v<n; v++){
            if(G[u][v] == 1 && visited[v] == 0)
                DFS(G, v, n);
        }
    }
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int G[20][20];
    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    printf("DFS Traversal: ");
    DFS(G, 0, n);

    return 0;
}
