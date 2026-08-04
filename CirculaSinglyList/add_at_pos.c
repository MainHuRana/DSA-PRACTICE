#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* next;
    int data;
};
struct Node* firstNode( int data){
    struct Node* temp =  (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}
struct Node* add_at_end(struct Node* tail, int data){
    struct Node* newP;
    newP = (struct Node*)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return newP;
}
struct Node* add_at_pos(struct Node* tail,int data,int pos){
    struct Node* newp = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* p = tail->next;
    newp->data = data;
    while(pos>1){
        p = p->next;
        pos--;
    }
    newp->next = p->next;
    p->next = newp;
    return tail;
}
void display(struct Node* tail){
    struct Node* p = tail->next;
   do{
    printf("%d ",p->data);
    p=p->next;
   }
while(p!=tail->next);
}
int main(){
    struct Node* tail;
    tail = (struct Node*)malloc(sizeof(struct Node));
    tail = firstNode(22);
    tail = add_at_end(tail,33);
    tail = add_at_end(tail,44);
    printf("linked list before insertion: ");
    display(tail);
    printf("\n");
    printf("linked list after insertion: ");
    tail = add_at_pos(tail,56,2);
    display(tail);

}