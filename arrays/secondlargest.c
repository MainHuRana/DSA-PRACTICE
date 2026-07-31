#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Step 1: find the largest element
    int largest = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > largest) {
            largest = nums[i];
        }
    }

    // Step 2: filter out all occurrences of largest into a new array
    int filtered[n];
    int m = 0; // size of filtered array
    for (int i = 0; i < n; i++) {
        if (nums[i] != largest) {
            filtered[m++] = nums[i];
        }
    }

    // Step 3: check if second largest exists
    if (m == 0) {
        printf("Second largest does not exist\n");
        return 0;
    }

    // Step 4: find max of filtered array
    int secondLargest = filtered[0];
    for (int i = 1; i < m; i++) {
        if (filtered[i] > secondLargest) {
            secondLargest = filtered[i];
        }
    }

    printf("Second largest element: %d\n", secondLargest);
    return 0;
}