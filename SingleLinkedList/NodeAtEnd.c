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
void InsertionAtEnd(struct Node* head){
    struct Node* temp;
    temp = (struct Node*)(malloc(sizeof(struct Node)));
    struct Node* ptr;
    ptr = head;
    temp->data=67;
    temp->next=NULL;
if(head==NULL){
        printf("The linked list is empty");
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    fourth = (struct Node*)(malloc(sizeof(struct Node)));
    head->data = 11;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 13;
    third->next = NULL;
    display(head);
    InsertionAtEnd(head);
    display(head);
}