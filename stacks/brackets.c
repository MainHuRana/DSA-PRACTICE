#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char);
char pop();
int isEmpty();
int isFull();
int check_balanced(char *);
int match_char(char, char);

int main(){
    char expr[MAX];
    int balanced;

    printf("enter the expression: ");
    fgets(expr, MAX, stdin);

    balanced = check_balanced(expr);

    if(balanced == 1){
        printf("Valid expression. ");
    }
    else{
        printf("Invalid expression. ");
    }

    return 0;
}

int check_balanced(char *s){
    char temp;
    int i;

    for(i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            push(s[i]);
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(isEmpty()){
                printf("right brackets are more than left. ");
                return 0;
            }
            else{
                temp = pop();
                if(!match_char(temp, s[i])){
                    printf("Mismatched brackets. ");
                    return 0;
                }
            }
        }
    }

    if(isEmpty()){
        printf("Number of right brackets equal to number of left brackets. ");
        return 1;
    }
    else{
        printf("Number of left brackets are greater than right brackets. ");
        return 0;
    }
}

void push(char c){
    if(isFull()){
        printf("Stack overflow. ");
        exit(1);
    }
    else{
        top++;
        stack[top] = c;
    }
}

char pop(){
    char c;
    if(isEmpty()){
        printf("stack is empty. ");
        exit(1);
    }
    c = stack[top];
    top--;
    return c;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top == MAX - 1){
        return 1;
    }
    else{
        return 0;
    }
}

int match_char(char a, char b){
    if(a == '[' && b == ']'){
        return 1;
    }
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    return 0;
}