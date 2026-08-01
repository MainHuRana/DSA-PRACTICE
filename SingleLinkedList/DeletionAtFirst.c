#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* DeletionNode(struct Node* head){
    struct Node* temp;
    if(head==NULL){
        printf("The linked list is empty");
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* ptr;

    head   = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third  = (struct Node*)(malloc(sizeof(struct Node)));

    head->data   = 11;  head->next   = second;
    second->data = 12;  second->next = third;
    third->data  = 13;  third->next  = NULL;

    ptr = head;
    printf("the linked list before deletion: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    head = DeletionNode(head);  // deletes 11

    ptr = head;
    printf("the linked list after deletion: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}