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
void Dis_DoublyLinkedList(struct Node* head){
    struct Node* ptr = head;
    while(ptr!=NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}
struct Node* createList(struct Node* head,int data,int n){
   printf("enter the number of nodes in the linked list: ");
   scanf("%d",&n);
   if(n==0){
    return head;
   }
   printf("enter the element of the first node: ");
   scanf("%d",&data);
   head = add_at_empty(head,data);
   for(int i=0;i<n;i++){
        printf("enter the element of the %d node: ");
        scanf("%d",&data);
        head = add_at_end(head,data);
   }
   return head;
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