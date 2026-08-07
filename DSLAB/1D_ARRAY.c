#include<stdio.h>

void display(int n, int arr[]){
    printf("The array elements are: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void linearsearch(int n,int arr[],int pos,int element){
    for(int i=0;i<n;i++){
        if(arr[i] == element){
            printf("the element %d is at %d",arr[i],pos);
        }
    }

}
int insertion(int n, int arr[], int pos, int element){
    for(int i = n; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    return n + 1;
}

int deletion(int n, int arr[], int element){
    int m = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != element){
            arr[m] = arr[i];
            m++;
        }
    }
    return m;
}

int main(){
    int n;
    int pos;
    printf("enter the size of the array: ");
    scanf("%d", &n);

    int arr[n+1]; // extra space for insertion
    printf("enter the array elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    display(n, arr);

    n = insertion(n, arr, 3, 11);
    display(n, arr);

    n = deletion(n, arr, 11);
    display(n, arr);
    linearsearch(n,arr,pos,1);
    return 0;
}