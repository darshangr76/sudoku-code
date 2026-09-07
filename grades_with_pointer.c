#include <stdio.h>

struct Student {
    char name[50];
    int id;
    float marks;
    char grade;
};

int main() {

    struct Student s;
    struct Student *ptr;

    ptr = &s;

    // Input
    printf("Enter student name: ");
    scanf("%s", ptr->name);

    printf("Enter student ID: ");
    scanf("%d", &ptr->id);

    printf("Enter marks: ");
    scanf("%f", &ptr->marks);

    // Calculate grade
    if (ptr->marks >= 90)
        ptr->grade = 'A';
    else if (ptr->marks >= 80)
        ptr->grade = 'B';
    else if (ptr->marks >= 70)
        ptr->grade = 'C';
    else if (ptr->marks >= 60)
        ptr->grade = 'D';
    else if (ptr->marks >= 50)
        ptr->grade = 'E';
    else
        ptr->grade = 'F';

    // Display
    printf("\n--- Student Details ---\n");
    printf("Name  : %s\n", ptr->name);
    printf("ID    : %d\n", ptr->id);
    printf("Marks : %.2f\n", ptr->marks);
    printf("Grade : %c\n", ptr->grade);

    return 0;
}