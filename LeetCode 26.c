
#include <stdio.h>

int removeDuplicates(int nums[], int n) {
    if (n == 0) {
        return 0;
    }

    int k = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[k - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main(void) {
    int nums[] = {1, 1, 2, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, n);

    printf("Unique elements: %d\n", k);
    printf("Array: ");

    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}
