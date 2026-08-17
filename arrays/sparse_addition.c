#include<stdio.h>
struct element{
    int rows;
    int cols;
    int value;
};
void add_sparse_matrix(struct element A[],struct element B[],struct element C[],int SizeA, int SizeB,int *SizeC){
    int i=0,j=0,k=0;
    while(i<SizeA && j<SizeB){
        if(A[i].rows == B[j].rows && A[i].cols == B[j].cols){
            C[k].rows = A[i].rows;
            C[k].cols = A[i].cols;
            C[k].value = A[i].value + B[j].value;
            k++;
            i++;
        j++;
        }
        else if(A[i].rows<B[j].rows|| A[i].rows == B[j].rows && A[i].cols<B[j].cols){
            C[k++] = A[i++];
        }
        else{
            C[k++] = B[j++];
        }
        
    }
    while (i<SizeA) C[k++] = A[i++];
    while (j<SizeB) C[k++] = B[j++];
*SizeC = k;

}
void print_matrix(struct element M[], int size){
    for(int idx=0;idx<size;idx++){
        printf("row=%d col=%d value=%d\n", M[idx].rows, M[idx].cols, M[idx].value);
    }
}
int main(){
    struct element A[10] = {
        {0,0,5},
        {1,2,3},
        {3,3,7}
    };
    int SizeA = 3;

    struct element B[10] = {
        {0,0,-5},
        {1,2,4},
        {2,1,6}
    };
    int SizeB = 3;

    struct element C[20];
    int SizeC = 0;

    add_sparse_matrix(A,B,C,SizeA,SizeB,&SizeC);

    printf("Matrix A:\n");
    print_matrix(A,SizeA);

    printf("Matrix B:\n");
    print_matrix(B,SizeB);

    printf("Result C = A+B:\n");
    print_matrix(C,SizeC);

    return 0;
}