#include <stdio.h>

int main() {
    // Open the file in read mode
    FILE *fptr = fopen("example.txt", "r");

    // Check if the file exists and opened successfully
    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read and print each character until the End of File (EOF)
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    // Close the file to free up system resources
    fclose(fptr);
    return 0;
}
