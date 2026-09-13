#include <stdio.h>

#define MAX_SUBJECTS 3
#define MAX_STUDENTS 3

// Structure representing an individual student
typedef struct {
    int id;
    char name[50];
    float grades[MAX_SUBJECTS]; // Array inside the structure
    float average;
} Student;

// Function to calculate the average grade for a student
void calculateAverage(Student *s) {
    float sum = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        sum += s->grades[i];
    }
    s->average = sum / MAX_SUBJECTS;
}

int main() {
    // Array of structures initialized with sample data
    Student students[MAX_STUDENTS] = {
        {101, "Alice", {85.5, 90.0, 78.5}, 0.0},
        {102, "Bob", {70.0, 65.5, 80.0}, 0.0},
        {103, "Charlie", {92.0, 88.0, 95.0}, 0.0}
    };

    // Calculate averages for each student
    for (int i = 0; i < MAX_STUDENTS; i++) {
        calculateAverage(&students[i]);
    }

    // Display the report card table
    printf("ID\tName\t\tGrades\t\t\tAverage\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%d\t%-10s\t", students[i].id, students[i].name);
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%.1f ", students[i].grades[j]);
        }
        printf("\t%.2f\n", students[i].average);
    }

    return 0;
}