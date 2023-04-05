#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50], data[100];
    int choice;

    printf("File Management System\n");
    printf("----------------------\n");

    while (1) {
        printf("\nMenu\n");
        printf("----\n");
        printf("1. Create a new file\n");
        printf("2. Read an existing file\n");
        printf("3. Update an existing file\n");
        printf("4. Delete an existing file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to create: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                if (fp == NULL) {
                    printf("Error creating file.\n");
                    exit(1);
                }
                printf("Enter the data to write to the file: ");
                scanf(" %[^\n]s", data);
                fprintf(fp, "%s", data);
                fclose(fp);
                printf("File created successfully.\n");
                break;

            case 2:
                printf("Enter the name of the file to read: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                while (fgets(data, 100, fp) != NULL) {
                    printf("%s", data);
                }
                fclose(fp);
                break;

            case 3:
                printf("Enter the name of the file to update: ");
                scanf("%s", filename);
                fp = fopen(filename, "r+");
                if (fp == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }
                printf("Enter the new data to write to the file: ");
                scanf(" %[^\n]s", data);
                fprintf(fp, "%s", data);
                fclose(fp);
                printf("File updated successfully.\n");
                break;

            case 4:
                printf("Enter the name of the file to delete: ");
                scanf("%s", filename);
                if (remove(filename) == 0) {
                    printf("File deleted successfully.\n");
                }
                else {
                    printf("Error deleting file.\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
