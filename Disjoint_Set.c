#include <stdio.h>

int parent[20], n;

/* Make set */
void makeSet() {
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = i;
}

/* Find */
int find(int x) {
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

/* Union */
void unionSet(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x != y) {
        parent[y] = x;
        printf("Union done\n");
    } else {
        printf("Already in same set\n");
    }
}

/* Display */
void display() {
    int i;
    printf("Element : Parent\n");
    for (i = 1; i <= n; i++)
        printf("%d : %d\n", i, parent[i]);
}

int main() {
    int ch, a, b;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet();

    while (1) {
        printf("\n--- Disjoint Set ---\n");
        printf("1. Find\n");
        printf("2. Union\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &a);
                printf("Set representative: %d\n", find(a));
                break;
            case 2:
                printf("Enter two elements: ");
                scanf("%d %d", &a, &b);
                unionSet(a, b);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
