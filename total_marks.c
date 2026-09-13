#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float marks[5];
    float average;
};

int main() {
    struct Student s[5];

    // Input details of 5 students
    for (int i = 0; i < 5; i++) {
        printf("\nEnter details for Student %d\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Student ID: ");
        scanf("%d", &s[i].id);

        float total = 0;

        printf("Enter marks for 5 subjects:\n");

        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);

            total += s[i].marks[j];
        }

        s[i].average = total / 5;
    }

    // Display details
    printf("\n========== STUDENT DETAILS ==========\n");

    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name    : %s\n", s[i].name);
        printf("ID      : %d\n", s[i].id);

        printf("Marks   : ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", s[i].marks[j]);
        }

        printf("\nAverage : %.2f\n", s[i].average);
    }

    return 0;
}