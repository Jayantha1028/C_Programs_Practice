#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char address[100];
    char phone[15];
};

int main() {
    FILE *fp, *temp;
    struct Contact c;
    int choice, found;
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

        switch(choice) {

        // Add Contact
        case 1:
            fp = fopen("directory.dat", "ab");

            printf("Enter Name: ");
            scanf(" %[^\n]", c.name);

            printf("Enter Address: ");
            scanf(" %[^\n]", c.address);

            printf("Enter Phone Number: ");
            scanf("%s", c.phone);

            fwrite(&c, sizeof(c), 1, fp);
            fclose(fp);

            printf("Contact Added Successfully!\n");
            break;

        // Delete Contact
        case 2:
            fp = fopen("directory.dat", "rb");
            temp = fopen("temp.dat", "wb");

            printf("Enter Name to Delete: ");
            scanf(" %[^\n]", search);

            found = 0;

            while (fread(&c, sizeof(c), 1, fp)) {
                if (strcmp(c.name, search) != 0)
                    fwrite(&c, sizeof(c), 1, temp);
                else
                    found = 1;
            }

            fclose(fp);
            fclose(temp);

            remove("directory.dat");
            rename("temp.dat", "directory.dat");

            if(found)
                printf("Contact Deleted Successfully!\n");
            else
                printf("Contact Not Found!\n");

            break;

        // Edit Contact
        case 3:
            fp = fopen("directory.dat", "rb+");

            printf("Enter Name to Edit: ");
            scanf(" %[^\n]", search);

            found = 0;

            while (fread(&c, sizeof(c), 1, fp)) {
                if (strcmp(c.name, search) == 0) {

                    printf("Enter New Address: ");
                    scanf(" %[^\n]", c.address);

                    printf("Enter New Phone Number: ");
                    scanf("%s", c.phone);

                    fseek(fp, -sizeof(c), SEEK_CUR);
                    fwrite(&c, sizeof(c), 1, fp);

                    found = 1;
                    break;
                }
            }

            fclose(fp);

            if(found)
                printf("Contact Updated Successfully!\n");
            else
                printf("Contact Not Found!\n");

            break;

        // Search Contact
        case 4:
            fp = fopen("directory.dat", "rb");

            printf("Enter Name to Search: ");
            scanf(" %[^\n]", search);

            found = 0;

            while (fread(&c, sizeof(c), 1, fp)) {
                if (strcmp(c.name, search) == 0) {
                    printf("\nName    : %s", c.name);
                    printf("\nAddress : %s", c.address);
                    printf("\nPhone   : %s\n", c.phone);
                    found = 1;
                    break;
                }
            }

            fclose(fp);

            if(!found)
                printf("Contact Not Found!\n");

            break;

        // Display All Contacts
        case 5:
            fp = fopen("directory.dat", "rb");

            if(fp == NULL) {
                printf("Directory is Empty!\n");
                break;
            }

            printf("\n--- Telephone Directory ---\n");

            while(fread(&c, sizeof(c), 1, fp)) {
                printf("\nName    : %s", c.name);
                printf("\nAddress : %s", c.address);
                printf("\nPhone   : %s\n", c.phone);
            }

            fclose(fp);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
