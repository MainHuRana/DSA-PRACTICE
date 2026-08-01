#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void InsertingAtPos(struct Node* head,int pos){
    struct Node* ptr = head;
    struct Node* ptr2;
    ptr2 = (struct Node*)(malloc(sizeof(struct Node)));
    ptr2->data = 67;
    ptr2->next = NULL;
    pos--;
    while(pos!=1){
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* ptr;
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    head->data = 11;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 13;
    third->next = NULL;
    ptr = head;
    printf("The nodes elements before inserting ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    InsertingAtPos(head,2);
    ptr = head;
    printf("The nodes elements after inserting: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}