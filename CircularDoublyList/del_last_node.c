#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* firstnode(struct Node* tail,int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct Node* add_at_end(struct Node* tail,int data){
    struct Node* head = tail->next;
    struct Node* newP = (struct Node*)(malloc(sizeof(struct Node)));
    newP->data = data;
    newP->prev = tail;
    tail->next = newP;
    newP->next = head;
    head->prev = newP;
    return newP; 
}
struct Node* add_at_pos(struct Node* tail, int data, int pos){
    struct Node* newP = (struct Node*)(malloc(sizeof(struct Node)));
    newP->data = data;
    struct Node* temp = tail->next;
    while(pos>1){
        temp = temp->next;
        pos--;
    }
    newP->prev = temp;
    newP->next = temp->next;
    temp->next->prev = newP;
    temp->next = newP;
    return tail;
}
struct Node* Del_first_Node(struct Node* tail){
    struct Node* temp = tail->next;
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    temp = NULL;
    return tail;
}
struct Node* del_last_node(struct Node* tail){
    struct Node* temp = tail->prev;
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    return tail;
}
void display(struct Node* tail){
    struct Node* head = tail->next;
    struct Node* temp = tail->next;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
}
int main(){
    struct Node* tail = NULL;
    tail = firstnode(tail,11);
    tail = add_at_end(tail,22);
    tail = add_at_end(tail,33);
    display(tail);
    printf("\n");
    tail = add_at_pos(tail,40,2);
    tail = del_last_node(tail);
    display(tail);
}