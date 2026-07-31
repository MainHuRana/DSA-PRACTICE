#include<stdio.h>
void merge_array(int n,int m,int arr[n],int arr2[m],int arr3[n+m]){
    int i=0,j=0,c=0;
    while(i<n&&j<m){
        if(arr[i]<arr2[j]){
            arr3[c++] = arr[i++];
        }
        else(arr[i]>arr2[j]){
            arr3[c++] = arr2[j++];
        }
    }
    
}
int main() {
    int n = 5, m = 5;
    int arr[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};
    int arr3[10];

    merge_array(n, m, arr, arr2, arr3);

    printf("Merged array: ");
    for (int i = 0; i < n+m; i++) {
        printf("%d ", arr3[i]);
    }
    return 0;
}