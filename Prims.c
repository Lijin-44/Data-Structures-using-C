#include <stdio.h>

#define INF 999

int main() {
    int n, cost[10][10], visited[10] = {0};
    int i, j, ne = 1;
    int mincost = 0;
    int u = 0, v = 0, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (visited[i]) {
                for (j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        ne++;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
