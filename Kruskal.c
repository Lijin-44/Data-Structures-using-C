#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j;
    int cost[MAX][MAX];
    int ne = 1, mincost = 0;
    int a = 0, b = 0, u = 0, v = 0, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("%d - %d : %d\n", a, b, min);
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum cost = %d\n", mincost);
    return 0;
}
