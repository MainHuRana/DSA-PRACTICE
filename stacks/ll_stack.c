#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int data);
void display();

int main() {
    int choice, data;

    while (1) {

        printf("\n=================================\n");
        printf("       STACK USING LINKED LIST\n");
        printf("=================================\n");
        printf("1. Push Element\n");
        printf("2. Display Stack\n");
        printf("3. Exit\n");
        printf("=================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter the element: ");
                scanf("%d", &data);

                push(data);

                printf("Element pushed successfully!\n");
                break;

            case 2:
                printf("\n---------- STACK ----------\n");
                display();
                printf("---------------------------\n");
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

void push(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    printf("TOP -> ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else 
    return 0;
}
int peek(){
    if(isEmpty()){
        printf("stack underflow");
        exit(1);
    }
    return top->data;
}
int pop(){
    struct Node* temp = top;
    int val;
    if(top==NULL){
        printf("stack underflow");

    }
    top->data = val;
    top = top->next;
    free(temp);
    temp = NULL;
    return val;
}