#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* CircularLinkedList(int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->data = data;
    temp->next = temp;
    return temp;
}
int main(){
    int data = 34;
    struct Node* tail = CircularLinkedList(data);
    printf("%d\n",tail->data);
}
