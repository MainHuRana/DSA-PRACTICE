#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
void Dis_Linked_list(struct Node* head){
    struct Node* ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
struct Node* add_at_empty(struct Node* head,int data){
    struct Node* temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;

}
struct Node* add_at_begin(struct Node* head,int data){
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
    struct Node* temp;
    temp = (struct Node*)(malloc(sizeof(struct Node)));
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
struct Node* CreateList(struct Node* head,int data,int n){
    printf("enter the number of nodes in the linked list: ");
    scanf("%d",&n);
    if(n==0){
        printf("the linked list is empty");
    }
    printf("enter the value of first node: ");
    scanf("%d",&data);
    head = add_at_empty(head,data);
    for(int i =1;i<n;i++){
        printf("enter the value of %d node: ",i+1);
        scanf("%d",&data);
        head = add_at_end(head,data);
    }
return head;
}
struct Node* del_first_node(struct Node* head){
    struct Node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    if (head != NULL) {          // FIX: only access head->prev if list is non-empty
        head->prev = NULL;
    }
    return head;
}
struct Node* del_at_pos(struct Node* head,int pos){
    struct Node* temp = head;
    struct Node* temp2 = head;
    while(pos>1){
        temp = temp->next;
        pos--;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    temp = NULL;
    return head;
}
int main(){
    struct Node* head = NULL;
     struct Node* ptr;
     int data,n;
    head = add_at_empty(head,34);
    head = add_at_end(head,22);
    head = add_at_begin(head,11);
    Dis_Linked_list(head);
    printf("\n");
    head = del_at_pos(head,2);
    Dis_Linked_list(head);
};