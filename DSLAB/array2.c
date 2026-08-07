#include<stdio.h>
void display(int n, int m,int arr[][m]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
    }
}
int NumberOfZeros(int n,int m,int arr[][m]){
    int count =0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(arr[i][j]!=0){
            count++;
           }
        }
    }
   return count;
}
int main(){
    int n,m;
    printf("enter the size of the matrix: ");
    scanf("%d%d",&n,&m);
    int arr[n][m];
    printf("enter the matrix elements: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    int result = NumberOfZeros(n, m, arr);
    printf("Number of non-zero elements: %d\n", result); 
}