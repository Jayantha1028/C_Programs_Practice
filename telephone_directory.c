#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char address[100];
    char phone[15];
};

int main() {
    struct Contact dir[100];
    int n = 0, choice, i, found;
    char search[50];

    do {
        printf("\n----- Telephone Directory -----\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: // Add
            printf("Enter Name: ");
            scanf(" %[^\n]", dir[n].name);

            printf("Enter Address: ");
            scanf(" %[^\n]", dir[n].address);

            printf("Enter Phone Number: ");
            scanf("%s", dir[n].phone);

            n++;
            printf("Contact Added Successfully!\n");
            break;

        case 2: // Delete
            printf("Enter Name to Delete: ");
            scanf(" %[^\n]", search);

            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(dir[i].name, search) == 0) {
                    int j;
                    for (j = i; j < n - 1; j++)
                        dir[j] = dir[j + 1];
                    n--;
                    found = 1;
                    printf("Contact Deleted Successfully!\n");
                    break;
                }
            }
            if (!found)
                printf("Contact Not Found!\n");
            break;

        case 3: // Edit
            printf("Enter Name to Edit: ");
            scanf(" %[^\n]", search);

            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(dir[i].name, search) == 0) {
                    printf("Enter New Address: ");
                    scanf(" %[^\n]", dir[i].address);

                    printf("Enter New Phone Number: ");
                    scanf("%s", dir[i].phone);

                    found = 1;
                    printf("Contact Updated Successfully!\n");
                    break;
                }
            }
            if (!found)
                printf("Contact Not Found!\n");
            break;

        case 4: // Search
            printf("Enter Name to Search: ");
            scanf(" %[^\n]", search);

            found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(dir[i].name, search) == 0) {
                    printf("\nContact Found:\n");
                    printf("Name    : %s\n", dir[i].name);
                    printf("Address : %s\n", dir[i].address);
                    printf("Phone   : %s\n", dir[i].phone);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Contact Not Found!\n");
            break;

        case 5: // Display
            if (n == 0) {
                printf("Directory is Empty!\n");
            } else {
                printf("\n--- Telephone Directory ---\n");
                for (i = 0; i < n; i++) {
                    printf("\nContact %d\n", i + 1);
                    printf("Name    : %s\n", dir[i].name);
                    printf("Address : %s\n", dir[i].address);
                    printf("Phone   : %s\n", dir[i].phone);
                }
            }
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}
