#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* del_at_last(struct Node* head){
    struct Node* temp1 = head;
    struct Node* temp2 = head;
    if(head == NULL){
        printf("the linked list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head = NULL;
    }
    else{
        while(temp1->link!=NULL){
        temp2 = temp1;
        temp1 = temp1->link;
        }
        temp2->link = NULL;
        free(temp1);
        temp1 = NULL;
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

    head->data   = 11;  head->link   = second;
    second->data = 12;  second->link = third;
    third->data  = 13;  third->link = NULL;

    ptr = head;
    printf("the linked list before deletion: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    head = del_at_last(head);  // deletes 11

    ptr = head;
    printf("the linked list after deletion: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");

    return 0;
}