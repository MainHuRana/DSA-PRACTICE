#include <stdio.h>

int SortedArray(int n, int arr[]) {
    int Sorted = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            Sorted = 0;
            break;
        }
    }
    return Sorted;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (SortedArray(n, arr))
        printf("1 (Sorted)\n");
    else
        printf("0 (Not Sorted)\n");

    return 0;
}
