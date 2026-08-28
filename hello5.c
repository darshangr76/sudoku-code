#include <stdio.h>

int main() {
    int a[5], b[5], result[5];
    int i;

    printf("Enter 5 elements of first array:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter 5 elements of second array:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }

    // Multiplication
    for (i = 0; i < 5; i++) {
        result[i] = a[i] * b[i];
    }

    printf("Result:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}