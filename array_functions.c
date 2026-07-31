#include <stdio.h>
#include <stdlib.h>

// Linear Search
void linearSearch(int *arr, int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i + 1);
            return;
        }
    }
    printf("Element not found.\n");
}

// Maximum and Minimum
void maxMin(int *arr, int n) {
    int i, max = arr[0], min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
}

// Sum of all elements
void sumArray(int *arr, int n) {
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += arr[i];

    printf("Sum of all elements = %d\n", sum);
}

// Sum of even and odd elements
void evenOddSum(int *arr, int n) {
    int i, even = 0, odd = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            even += arr[i];
        else
            odd += arr[i];
    }

    printf("Sum of Even Elements = %d\n", even);
    printf("Sum of Odd Elements = %d\n", odd);
}

// Check palindrome
void palindrome(int *arr, int n) {
    int i;

    for (i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            printf("Array is NOT Palindrome.\n");
            return;
        }
    }

    printf("Array is Palindrome.\n");
}

// Find pair with sum M
void subsetSum(int *arr, int n, int M) {
    int i, j, found = 0;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == M) {
                printf("Pair Found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found)
        printf("No pair found with sum %d\n", M);
}

// Free memory
void deallocate(int *arr) {
    free(arr);
    printf("Memory Deallocated Successfully.\n");
}

int main() {
    int *arr;
    int n, i, key, M;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // (a) Linear Search
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    linearSearch(arr, n, key);

    // (b) Max and Min
    maxMin(arr, n);

    // (c) Sum of all elements
    sumArray(arr, n);

    // (d) Sum of even and odd elements
    evenOddSum(arr, n);

    // (e) Palindrome
    palindrome(arr, n);

    // (f) Pair with sum M
    printf("Enter value of M: ");
    scanf("%d", &M);
    subsetSum(arr, n, M);

    // (g) Free memory
    deallocate(arr);

    return 0;
}
