#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char date[15];
    char category[30];
    char description[100];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int count = 0;

void addExpense() {
    if (count >= MAX_EXPENSES) {
        printf("\nExpense limit reached!\n");
        return;
    }

    printf("\nEnter date (DD-MM-YYYY): ");
    scanf("%14s", expenses[count].date);

    printf("Enter category: ");
    scanf(" %29[^\n]", expenses[count].category);

    printf("Enter description: ");
    scanf(" %99[^\n]", expenses[count].description);

    printf("Enter amount: ");
    scanf("%f", &expenses[count].amount);

    count++;

    printf("\nExpense added successfully!\n");
}

void viewExpenses() {
    if (count == 0) {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("\n========== EXPENSES ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nExpense %d\n", i + 1);
        printf("Date        : %s\n", expenses[i].date);
        printf("Category    : %s\n", expenses[i].category);
        printf("Description : %s\n", expenses[i].description);
        printf("Amount      : ₹%.2f\n", expenses[i].amount);
    }
}

void totalExpenses() {
    float total = 0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Expenses: ₹%.2f\n", total);
}

void saveExpenses() {
    FILE *file = fopen("expenses.dat", "wb");

    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(expenses, sizeof(Expense), count, file);

    fclose(file);

    printf("\nExpenses saved successfully!\n");
}

void loadExpenses() {
    FILE *file = fopen("expenses.dat", "rb");

    if (file == NULL) {
        return;
    }

    fread(&count, sizeof(int), 1, file);
    fread(expenses, sizeof(Expense), count, file);

    fclose(file);
}

int main() {
    int choice;

    loadExpenses();

    do {
        printf("\n================================\n");
        printf("        EXPENSE TRACKER\n");
        printf("================================\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Save Expenses\n");
        printf("5. Exit\n");
        printf("================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                totalExpenses();
                break;

            case 4:
                saveExpenses();
                break;

            case 5:
                saveExpenses();
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}