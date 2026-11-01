
#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int position = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            int temp = nums[position];
            nums[position] = nums[i];
            nums[i] = temp;

            position++;
        }
    }
}

int main(void) {
    int nums[] = {0, 1, 0, 3, 12};
    int n = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, n);

    printf("Output: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");
    return 0;
}
