#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    struct Node* head = (struct Node*)(malloc(sizeof(struct Node)));
    printf("enter the value of head: ");
    scanf("%d",&head->data);
    head->next=NULL;
    printf("%d",head->data);
}