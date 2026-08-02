#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* add_at_empty(struct Node* head,int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;

}
struct Node* add_at_beg(struct Node* head,int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;

}
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
struct Node* add_at_pos(struct Node* head,int data,int pos){
    struct Node* temp = head;
    struct Node* temp2 = NULL;
    struct Node* newP = NULL;
    newP =(struct Node*)(malloc(sizeof(struct Node)));
    newP->prev = NULL;
    newP->data = data;
    newP->next= NULL;
    while(pos!=1){
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = newP;
    newP->prev = temp;
    temp2->prev = newP;
    newP->next = temp2;
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
    int pos = 2;
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
    add_at_pos(head,67,2);
    Dis_DoublyLinkedList(head);
}