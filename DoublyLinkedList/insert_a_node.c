#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
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
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    head->prev   = NULL;    second->prev  = head;    third->prev  = second;
    head->data   = 10;      second->data  = 20;      third->data  = 30;
    head->next   = second;  second->next  = third;   third->next  = NULL;
    Dis_DoublyLinkedList(head);
}