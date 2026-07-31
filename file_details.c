#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *destination;
    char ch;
    char file[100];

    printf("Enter the source file name: ");
    scanf("%s", file);

    source = fopen(file, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file.\n");
        return 1;
    }
    int count = 0, sp = 0, nl = 0;
    while ((ch = fgetc(source)) != EOF) {
        count++;
        if (ch == '\t') sp++;
        if (ch == '\n') nl++;
    }

    fclose(source);

    printf("Total characters in the file is : %d\n", count);
    printf("Total tabs in the file is : %d\n", sp);
    printf("Total new lines in the file is : %d\n", nl);
    return 0;
}
