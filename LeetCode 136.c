
#include <stdio.h>

int singleNumber(int nums[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= nums[i];
    }

    return result;
}

int main(void) {
    int nums[] = {4, 1, 2, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Single number: %d\n", singleNumber(nums, n));

    return 0;
}
