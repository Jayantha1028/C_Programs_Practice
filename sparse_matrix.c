#include <stdio.h>

int main() {
    int rows, cols, count = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];

    printf("Enter the elements of the matrix:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);

            if(mat[i][j] == 0)
                count++;
        }
    }

    if(count > (rows * cols) / 2)
        printf("Sparse Matrix");
    else
        printf("Not a Sparse Matrix");

    return 0;
}
