#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void display(struct Node* ptr){
    printf("\nThe elements in the linked list: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* ptr;
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    fourth = (struct Node*)(malloc(sizeof(struct Node)));
    ptr = (struct Node*)(malloc(sizeof(struct Node)));
    head->data = 11;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 13;
    third->next = NULL;
    ptr->data = 67;
    ptr->next = head;
    head = ptr;
    display(head);
    
}