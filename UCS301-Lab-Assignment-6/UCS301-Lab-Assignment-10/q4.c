#include <stdio.h>

int find(int u, int parent[]){
    while(parent[u] != u)
        u = parent[u];
    return u;
}

void Union(int u, int v, int parent[]){
    parent[v] = u;
}

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int cost[20][20];
    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    int parent[20];
    for(int i=0;i<n;i++) parent[i] = i;

    int ne = 0, mincost = 0;

    printf("Edges in MST:\n");
    while(ne < n - 1){
        int min = 999, a=-1, b=-1;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(cost[i][j] < min && cost[i][j] != 0){
                    min = cost[i][j];
                    a = i; b = j;
                }

        int u = find(a, parent);
        int v = find(b, parent);

        if(u != v){
            printf("%d - %d = %d\n", a, b, min);
            mincost += min;
            Union(u, v, parent);
            ne++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;
}
