#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;
int queue[100];

int isEmpty();
int isFull();
void enqueue(int data);
int dequeue();
int peek();
void print();

int main(){
    int choice, data;
    while(1){
        printf("1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 5) break;

        switch(choice){
            case 1:
                printf("enter the element to be added: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                if(!isEmpty())
                    printf("The deleted element is: %d\n", dequeue());
                else
                    printf("Queue is empty.\n");
                break;
            case 3:
                if(!isEmpty())
                    printf("The element in the front is: %d\n", peek());
                else
                    printf("Queue is empty.\n");
                break;
            case 4:
                print();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return (rear == 100 - 1);
}

void enqueue(int data){
    if(isFull()){
        printf("list is full.\n");
        return;
    }
    if(isEmpty()){
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

int dequeue(){
    int data;
    if(isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    data = queue[front];
    if(front == rear){
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}

int peek(){
    if(isEmpty()){
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue[front];
}

void print(){
    int i;
    if(isEmpty()){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for(i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}