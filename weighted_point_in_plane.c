#include <stdio.h>

// Structure definition
struct Point {
    int x;
    int y;
    int weight;
};

int main() {
    int n, i, j;
    struct Point p[100];

    int maxWeight, maxIndex;
    int vertical = 0, horizontal = 0;

    printf("Enter number of points: ");
    scanf("%d", &n);

    // Input points
    for (i = 0; i < n; i++) {
        printf("Enter x, y and weight of point %d: ", i + 1);
        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].weight);
    }

    // Find point with maximum weight
    maxWeight = p[0].weight;
    maxIndex = 0;

    for (i = 1; i < n; i++) {
        if (p[i].weight > maxWeight) {
            maxWeight = p[i].weight;
            maxIndex = i;
        }
    }

    // Count vertical and horizontal lines
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].x == p[j].x)
                vertical++;

            if (p[i].y == p[j].y)
                horizontal++;
        }
    }

    // Output
    printf("\nPoint with Maximum Weight:\n");
    printf("(%d, %d)  Weight = %d\n",
           p[maxIndex].x,
           p[maxIndex].y,
           p[maxIndex].weight);

    printf("\nNumber of Vertical Lines   = %d\n", vertical);
    printf("Number of Horizontal Lines = %d\n", horizontal);

    return 0;
}
