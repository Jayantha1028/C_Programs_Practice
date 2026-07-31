#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *destination;
    char ch;
    char sourceFile[100], destFile[100];

    printf("Enter the source file name: ");
    scanf("%s", sourceFile);

    printf("Enter the destination file name: ");
    scanf("%s", destFile);

    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file.\n");
        return 1;
    }

    destination = fopen(destFile, "a");
    if (destination == NULL) {
        printf("Error: Cannot create destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
