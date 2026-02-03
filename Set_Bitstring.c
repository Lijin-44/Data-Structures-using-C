#include <stdio.h>

int main() {
    int A[10], B[10], U[10], I[10], D[10];
    int i, n;

    printf("Enter number of elements in universal set: ");
    scanf("%d", &n);

    printf("Enter bit string for Set A:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter bit string for Set B:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &B[i]);

    /* Union */
    for (i = 0; i < n; i++)
        U[i] = A[i] | B[i];

    /* Intersection */
    for (i = 0; i < n; i++)
        I[i] = A[i] & B[i];

    /* Difference A - B */
    for (i = 0; i < n; i++)
        D[i] = A[i] & (~B[i]);

    printf("\nSet A: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nSet B: ");
    for (i = 0; i < n; i++)
        printf("%d ", B[i]);

    printf("\nUnion: ");
    for (i = 0; i < n; i++)
        printf("%d ", U[i]);

    printf("\nIntersection: ");
    for (i = 0; i < n; i++)
        printf("%d ", I[i]);

    printf("\nDifference (A - B): ");
    for (i = 0; i < n; i++)
        printf("%d ", D[i]);

    return 0;
}
