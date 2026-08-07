#include<stdio.h>

void display(int arr[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void sparsematrix(int arr[][3]){
  
     int count =0,k=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    int sparse[3][3];
    sparse[0][0] = 3;
    sparse[0][1] = 3;
    sparse[0][2] = 9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
        printf("\n");
    }
   printf("rows\tcols\tvalue\n");
       for(int i=0;i<=count;i++){
        printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
       }
}
int main(){
    int arr[3][3] = {{0,0,1},{0,3,5},{1,0,0}};

    display(arr);
    sparsematrix(arr);

    return 0;
}