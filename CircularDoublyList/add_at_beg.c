#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* CreateFirstNode(struct Node* tail,int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* add_at_beg(struct Node* tail,int data){
    struct Node* newP = (struct Node*)(malloc(sizeof(struct Node)));
    newP->prev = NULL;
    newP->data = data;
    newP->next = NULL;
    if(newP==NULL){
        return newP;
    }
    struct Node* temp =  (struct Node*)(malloc(sizeof(struct Node)));
    newP->prev = temp;
    newP->next = tail;
    temp->prev = newP;
    tail->next = newP;
    return tail;
}
void display(struct Node* tail){
    struct Node* temp;
    if(tail == NULL){
        printf("the list is empty");
    }
    else{
        struct Node* temp = tail->next;
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp!=tail->next);

    }
    printf("\n");
}
int main(){
    struct Node* tail = NULL;
    tail = CreateFirstNode(tail,11);
    tail = add_at_beg(tail,12);
    display(tail);
}