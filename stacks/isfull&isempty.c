#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stack_arr[4];
int top = -1; // this indicates that stack is full
void push(int data){
    if(top == MAX-1){
        printf("stack overflow");
        return;
    }
    top = top+1;
    stack_arr[top] = data;
}
int isempty(){          // added: used in peek() but never defined
    return top == -1;
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
int peek(){
    if(isempty()){
        printf("stack underflow");
        exit(1);
    }
    return stack_arr[top];
}
void display(){
    if(top==-1){
        printf("stack underflow");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d",stack_arr[i]);
        printf("\n");
    }
}
int main(){
    int choice,data;
    while(1){
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.print the top elements\n");
        printf("4.print all the elements of the stack\n");
        printf("5.Quit\n");
        printf("please enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter the element to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("%d popped\n",pop());
                break;
            case 3:
                printf("the topmost element here is %d",peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
            printf("wrong choice");
        }
    }
}