
#include <stdio.h>

int findMaxConsecutiveOnes(int nums[], int n) {
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;

            if (count > maxCount) {
                maxCount = count;
            }
        } else {
            count = 0;
        }
    }

    return maxCount;
}

int main(void) {
    int nums[] = {1, 1, 0, 1, 1, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum consecutive ones: %d\n",
           findMaxConsecutiveOnes(nums, n));

    return 0;
}
