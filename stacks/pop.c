#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[4];
int top=-1;
void display(int data,int stack_arr[]){
    if(top==-1){
        printf("stack is empty");
        exit(1);
    }
    for(int i=top;i>=0;i--){
        printf("%d",stack_arr[i]);

    }
}
void push(int data){
    if(top == MAX-1){
        printf("stack overflow");
        return;
    }
    top = top+1;
    stack_arr[top] = data;
}
int pop(){
    int value;
    if(top==-1){
        printf("stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top = top-1;
    return value;
}
int main(){
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    data = pop();
    display(0, stack_arr);
}
