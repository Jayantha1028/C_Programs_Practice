#include <stdio.h>

// Function to find Union
void set_union(int A[], int n1, int B[], int n2) {
    int i, j;

    printf("Union: { ");

    // Print all elements of A
    for (i = 0; i < n1; i++)
        printf("%d ", A[i]);

    // Print only those elements of B not present in A
    for (i = 0; i < n2; i++) {
        int found = 0;
        for (j = 0; j < n1; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            printf("%d ", B[i]);
    }

    printf("}\n");
}

// Function to find Intersection
void set_intersection(int A[], int n1, int B[], int n2) {
    int i, j;

    printf("Intersection: { ");

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }

    printf("}\n");
}

// Function to find Difference
void set_difference(int A[], int n1, int B[], int n2) {
    int i, j, found;

    printf("A - B: { ");
    for (i = 0; i < n1; i++) {
        found = 0;
        for (j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            printf("%d ", A[i]);
    }
    printf("}\n");

    printf("B - A: { ");
    for (i = 0; i < n2; i++) {
        found = 0;
        for (j = 0; j < n1; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found)
            printf("%d ", B[i]);
    }
    printf("}\n");
}

int main() {
    int A[50], B[50];
    int n1, n2, i;

    printf("Enter number of elements in Set A: ");
    scanf("%d", &n1);

    printf("Enter elements of Set A: ");
    for (i = 0; i < n1; i++)
        scanf("%d", &A[i]);

    printf("Enter number of elements in Set B: ");
    scanf("%d", &n2);

    printf("Enter elements of Set B: ");
    for (i = 0; i < n2; i++)
        scanf("%d", &B[i]);

    set_union(A, n1, B, n2);
    set_intersection(A, n1, B, n2);
    set_difference(A, n1, B, n2);

    return 0;
}
