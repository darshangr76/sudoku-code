
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int nums[], int n, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    free(result);
    *returnSize = 0;
    return NULL;
}

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;

    int* result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }

    return 0;
}
