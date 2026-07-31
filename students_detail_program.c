#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct Student {
    int roll;
    char name[50];
    int age;
    float marks;
};

int main() {
    int n, i, roll, found = 0;
    char searchName[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    struct Student *s;
    s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    // Input student details
    printf("\nEnter Student Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Age: ");
        scanf("%d", &s[i].age);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    // (i) Search by Roll Number
    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    found = 0;
    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Age     : %d\n", s[i].age);
            printf("Marks   : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Student not found.\n");

    // (ii) Search by Name
    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]", searchName);

    found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(s[i].name, searchName) == 0) {
            printf("\nStudent Found:\n");
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Age     : %d\n", s[i].age);
            printf("Marks   : %.2f\n", s[i].marks);
            found = 1;
        }
    }
    if (!found)
        printf("Student not found.\n");

    // (iii) Student with Highest Marks
    int maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (s[i].marks > s[maxIndex].marks)
            maxIndex = i;
    }

    printf("\nStudent with Highest Marks:\n");
    printf("Roll No : %d\n", s[maxIndex].roll);
    printf("Name    : %s\n", s[maxIndex].name);
    printf("Age     : %d\n", s[maxIndex].age);
    printf("Marks   : %.2f\n", s[maxIndex].marks);

    // (iv) Students whose name begins with 'A'
    printf("\nStudents whose name begins with 'A':\n");
    found = 0;

    for (i = 0; i < n; i++) {
        if (s[i].name[0] == 'A' || s[i].name[0] == 'a') {
            printf("\nRoll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Age     : %d\n", s[i].age);
            printf("Marks   : %.2f\n", s[i].marks);
            found = 1;
        }
    }

    if (!found)
        printf("No student name begins with 'A'.\n");

    // (v) Deallocate Memory
    free(s);
    printf("\nMemory Deallocated Successfully.\n");

    return 0;
}
