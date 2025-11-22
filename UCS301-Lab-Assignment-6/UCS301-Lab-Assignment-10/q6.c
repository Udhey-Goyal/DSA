#include <stdio.h>

int main(){
    int n, source;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[20][20];
    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&source);

    int dist[20], visited[20]={0};

    for(int i=0;i<n;i++)
        dist[i] = cost[source][i];

    visited[source] = 1;

    for(int count=1;count<n;count++){
        int min = 999, u=-1;

        for(int i=0;i<n;i++)
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for(int v=0;v<n;v++)
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    printf("Shortest distances:\n");
    for(int i=0;i<n;i++)
        printf("%d ", dist[i]);

    return 0;
}
