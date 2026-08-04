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
struct Node* circularLinkedList(struct Node* tail,int n,int data){
    printf("enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    if(n==0){
        return tail;
    }
    printf("enter the data of the first node: ");
    scanf("%d",&data);
    tail = firstNode(data);
    for(int i=1;i<n;i++){
        printf("enter the data of the %d node: ",i+1);
        scanf("%d",&data);
        tail = add_at_end(tail,data);
    }
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
    circularLinkedList(tail,3,22);
    display(tail);

}