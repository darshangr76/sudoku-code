
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* intersection(int nums1[], int n1,
                  int nums2[], int n2,
                  int* returnSize) {

    int* result = malloc(n1 * sizeof(int));
    bool seen[1001] = {false};
    bool added[1001] = {false};

    *returnSize = 0;

    for (int i = 0; i < n1; i++) {
        seen[nums1[i]] = true;
    }

    for (int i = 0; i < n2; i++) {
        int value = nums2[i];

        if (seen[value] && !added[value]) {
            result[(*returnSize)++] = value;
            added[value] = true;
        }
    }

    return result;
}

int main(void) {
    int nums1[] = {1, 2, 2, 1};
    int nums2[] = {2, 2};

    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    int n2 = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;

    int* result = intersection(
        nums1, n1, nums2, n2, &returnSize
    );

    printf("Intersection: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    free(result);
    return 0;
}
