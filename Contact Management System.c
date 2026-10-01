#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[60];
} Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;

void saveContacts() {
    FILE *file = fopen("contacts.dat", "wb");

    if (file == NULL) {
        printf("Error saving contacts!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(contacts, sizeof(Contact), count, file);

    fclose(file);
}

void loadContacts() {
    FILE *file = fopen("contacts.dat", "rb");

    if (file == NULL)
        return;

    fread(&count, sizeof(int), 1, file);
    fread(contacts, sizeof(Contact), count, file);

    fclose(file);
}

void addContact() {
    if (count >= MAX_CONTACTS) {
        printf("\nContact limit reached!\n");
        return;
    }

    printf("\nEnter name: ");
    scanf(" %49[^\n]", contacts[count].name);

    printf("Enter phone number: ");
    scanf(" %19s", contacts[count].phone);

    printf("Enter email: ");
    scanf(" %59s", contacts[count].email);

    count++;

    saveContacts();

    printf("\nContact added successfully!\n");
}

void displayContacts() {
    if (count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n========== CONTACTS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

void searchContact() {
    char searchName[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf(" %49[^\n]", searchName);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, searchName) == 0) {
            printf("\nContact found!\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nContact not found.\n");
}

void deleteContact() {
    char name[50];
    int found = -1;

    printf("\nEnter name to delete: ");
    scanf(" %49[^\n]", name);

    for (int i = 0; i < count; i++) {
        if (strcasecmp(contacts[i].name, name) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nContact not found.\n");
        return;
    }

    for (int i = found; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    count--;

    saveContacts();

    printf("\nContact deleted successfully!\n");
}

int main() {
    int choice;

    loadContacts();

    do {
        printf("\n================================\n");
        printf("     CONTACT MANAGEMENT SYSTEM\n");
        printf("================================\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
                break;

            case 5:
                saveContacts();
                printf("\nThank you for using Contact Management System!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}