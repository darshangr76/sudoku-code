
#include <stdio.h>

int missingNumber(int nums[], int n) {
    int sum = n * (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        sum -= nums[i];
    }

    return sum;
}

int main(void) {
    int nums[] = {3, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Missing number: %d\n",
           missingNumber(nums, n));

    return 0;
}
