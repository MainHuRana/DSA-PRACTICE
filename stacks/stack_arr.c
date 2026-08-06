#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top =-1;
void push(int data){
    if(top == MAX-1){
        printf("stack overflow\n");
        return;
    }
    top = top+1;
        for(int i=top;i>0;i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}
void print(){
    if(top==-1){
        printf("stack empty");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d ",stack_arr[i]);
    }
}
int main(){
    push(30);
    push(90);
    print();
}