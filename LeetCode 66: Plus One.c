
#include <stdio.h>
#include <stdlib.h>

int* plusOne(int digits[], int n, int* returnSize) {
    int* result = malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        result[i] = digits[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (result[i] < 9) {
            result[i]++;
            *returnSize = n;
            return result;
        }

        result[i] = 0;
    }

    result[0] = 1;
    *returnSize = n + 1;
    return result;
}

int main(void) {
    int digits[] = {9, 9, 9};
    int n = sizeof(digits) / sizeof(digits[0]);
    int returnSize = 0;

    int* result = plusOne(digits, n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    free(result);
    return 0;
}
