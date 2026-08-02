#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* add_at_end(struct Node* head,int data){
    struct Node* tp;
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while(tp->next!=NULL){
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}
void Dis_DoublyLinkedList(struct Node* head){
    struct Node* ptr = head;
    while(ptr!=NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* temp;
    temp = (struct Node*)(malloc(sizeof(struct Node)));
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    head->prev   = NULL;    second->prev  = head;    third->prev  = second;
    head->data   = 10;      second->data  = 20;      third->data  = 30;
    head->next   = second;  second->next  = third;   third->next  = NULL;
    printf("linked list before adding the first node at the end: ");
    printf("\n");
    Dis_DoublyLinkedList(head);
    printf("linked list after adding the first node at the end: ");
    printf("\n");
    head = add_at_end(head,9);
    Dis_DoublyLinkedList(head);
}