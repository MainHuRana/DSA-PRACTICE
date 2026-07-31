#include<stdio.h>
void display(int n,int arr[]){
    printf("the array elements are: ");
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void ReverseArray(int arr[],int n){
    printf("the array elements in reverse are: ");
    for(int i = n-1;i>=0;i--){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("enter the no. array elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    display(n,arr);
    ReverseArray(arr,n);
}