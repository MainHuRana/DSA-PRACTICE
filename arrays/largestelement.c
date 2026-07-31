#include <stdio.h>

int largestElement(int nums[], int size) {
    int result = nums[0];
    for (int i = 1; i < size; i++) {
        if (nums[i] > result) {
            result = nums[i];
        }
    }
    return result;
}

int main() {
    int nums[] = {3, 3, 6, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", largestElement(nums, size));
    return 0;
}