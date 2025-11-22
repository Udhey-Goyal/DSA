#include <stdio.h>

int main(){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[20][20];
    printf("Enter cost adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    int selected[20] = {0};
    selected[0] = 1;

    int ne = 0, mincost = 0;

    printf("Edges in MST:\n");
    while(ne < n-1){
        int min = 999, a = -1, b = -1;

        for(int i=0;i<n;i++){
            if(selected[i]){
                for(int j=0;j<n;j++){
                    if(!selected[j] && cost[i][j] < min){
                        min = cost[i][j];
                        a = i; b = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", a, b, min);
        mincost += min;
        selected[b] = 1;
        ne++;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;
}
