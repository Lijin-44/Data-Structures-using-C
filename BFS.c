#include <stdio.h>

int n;
int adj[20][20];
int visited[20];
int queue[20];
int front = -1, rear = -1;

/* Enqueue */
void enqueue(int v) {
    if (rear == n - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

/* Dequeue */
int dequeue() {
    if (front == -1)
        return -1;
    int v = queue[front++];
    if (front > rear)
        front = rear = -1;
    return v;
}

/* BFS */
void bfs(int start) {
    int i, v;
    for (i = 1; i <= n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal: ");

    while (front != -1) {
        v = dequeue();
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
