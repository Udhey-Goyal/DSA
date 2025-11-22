#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int G[20][20];

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Number of edges
    int edges = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (G[i][j] == 1) edges++;

    printf("\nNumber of edges = %d\n", edges);

    // Degrees
    for (i = 1; i <= n; i++) {
        int indeg = 0, outdeg = 0;

        for (j = 1; j <= n; j++) {
            if (G[j][i] == 1) indeg++;
            if (G[i][j] == 1) outdeg++;
        }

        printf("\nVertex %d → In-degree = %d, Out-degree = %d\n", i, indeg, outdeg);

        printf("Adjacent to %d: ", i);
        for (j = 1; j <= n; j++)
            if (G[i][j] == 1) printf("%d ", j);
        printf("\n");
    }

    return 0;
}
