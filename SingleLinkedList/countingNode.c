#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void display(struct Node* ptr)
{
    printf("The nodes elements are: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void Nodecounting(struct Node* ptr){
    int count=0;
     if(ptr==NULL){
            printf("THE LINKED LIST IS EMPTY");
        }
    while(ptr!=NULL){
            count++;
            ptr = ptr->next;
    }
    printf("The number of nodes in this linked list is: %d\n",count);
}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head = (struct Node*)(malloc(sizeof(struct Node)));
    second = (struct Node*)(malloc(sizeof(struct Node)));
    third = (struct Node*)(malloc(sizeof(struct Node)));
    head->data = 11;
    head->next = second;
    second->data = 12;
    second->next = third;
    third->data = 13;
    third->next = NULL;
    Nodecounting(head);
    display(head);
}