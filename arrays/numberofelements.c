#include<stdio.h>
void count(int n,int arr[]){
    int counter = 0;
    for(int i=0;i<n;i++){
        arr[i] = counter++;
    }
    printf("no. of elements = %d",counter);
}
void display(int n,int arr[]){
    printf("the array elements are as follows: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("enter the no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements: ");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    display(n,arr);
    count(n,arr);


}