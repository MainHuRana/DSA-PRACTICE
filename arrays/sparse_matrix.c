#include<stdio.h>
void sparse_matrix(int n,int m,int arr[n][m]){
    int count =0,k=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    int sparse[count+1][3];
    sparse[0][0] = "rows";
    sparse[0][1] = "";
    sparse[0][2] = count;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=arr[i][j];
                k++;
            }
            }
        }
       printf("this is the sparse matrix:\n");
       printf("rows\tcols\tvalue\n");
       for(int i=0;i<=count;i++){
        printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
       }
    }
int main(){
    int n,m;
    printf("enter the dimension of your matrix: ");
    scanf("%d%d",&n,&m);
    int arr[n][m];
    printf("enter the matrix elements: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("your matrix is: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",arr[i][j]);
        }
    }
    sparse_matrix(n,m,arr);
}