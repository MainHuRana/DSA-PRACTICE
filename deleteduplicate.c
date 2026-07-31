#include<stdio.h>
int deletion(int n, int arr[],int new_array[]){
   
    int m=0;
    for(int i=0;i<n;i++){
         int found = 0;
        for(int j = 0;j<i;j++){
            if(arr[i]==arr[j]){
                found = 1;
                break;
            }
        }
        if(!found){
            new_array[m] = arr[i];
            m++;
        }
    }
    return m;
}
int main(){
    int n =6;
   int  arr[6] = {1,2,3,4,5,5};
   int new_array[6];
    int m = deletion(n,arr,new_array);
   printf("Array without duplicates: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", new_array[i]);
    }
    printf("\n");
}