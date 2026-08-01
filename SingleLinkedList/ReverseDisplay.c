#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createList(int n)
{
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
        printf("enter the node element: ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        newNode = NULL;
    }
}
void displayNode(struct Node* ptr){
    while(ptr!=NULL)
    {
    printf("%d\n",ptr->data);
    ptr = ptr->next;
    }
}
int main(){
    int n;
    struct Node* head = createList( n);
    displayNode(head);
}