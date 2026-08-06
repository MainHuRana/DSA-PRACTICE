#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m = nums1Size + nums2Size;
    int i = 0, j = 0, k = 0;

    int* merged_array = (int*)malloc(m * sizeof(int));

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] <= nums2[j]) {
            merged_array[k++] = nums1[i++];
        } else {
            merged_array[k++] = nums2[j++];
        }
    }
    while (i < nums1Size) {
        merged_array[k++] = nums1[i++];
    }
    while (j < nums2Size) {
        merged_array[k++] = nums2[j++];
    }

    double median;
    if (m % 2 == 0) {
        median = (merged_array[m / 2 - 1] + merged_array[m / 2]) / 2.0;
    } else {
        median = merged_array[m / 2];
    }

    free(merged_array);
    return median;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    double result = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median: %.5f\n", result);

    int nums3[] = {1, 2};
    int nums4[] = {3, 4};

    double result2 = findMedianSortedArrays(nums3, 2, nums4, 2);
    printf("Median: %.5f\n", result2);

    return 0;
}