#include<stdio.h>

void display(int n, int m, int arr[n][m]){
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
    }
}

// returns how many elements were kept
int deletion(int n, int m, int arr[n][m], int target, int new_array[n*m]){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != target){
                new_array[count] = arr[i][j];
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n, m;
    printf("enter the dimensions of the array: ");
    scanf("%d%d", &n, &m);
    int arr[n][m];
    printf("enter the array elements: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int target = arr[0][3];  // careful: assumes m > 3
    int new_array[n*m];      // flat array since result size varies

    display(n, m, arr);
    int count = deletion(n, m, arr, target, new_array);

    printf("\n\nArray after deletion:\n");
    for(int i = 0; i < count; i++){
        for(int j=0;j<count;j++){
        printf("%d ", new_array[i]);
    }
    printf("\n");
}