#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
void Dis_Doubly_LinkedList(struct Node* head){
    struct Node* ptr = head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr = ptr->next; 
    }
}
int main(){
    struct Node* head;
    head = (struct Node*)(malloc(sizeof(struct Node)));
    head->data = 16;
    head->prev=NULL;
    head->next = NULL;
    Dis_Doubly_LinkedList(head);
}