#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void display(struct Node* tail){
    struct Node* p = tail->next;
    do{
      printf("%d\n",p->data);
      p = p->next;
    }
    while(p!=tail->next);
}
struct Node* add_at_end(struct Node* tail,int data){
    struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}
int main(){
    struct Node* tail;
    tail = (struct Node*)malloc(sizeof(struct Node));
    tail->data = 36;
    tail->next = tail;
    tail = add_at_end(tail,35);
    tail = add_at_end(tail,44);
    display(tail);
}