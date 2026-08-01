#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void LinkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
         printf("elements: %d\n",ptr->data);
         ptr = ptr->next;
    }
}
int main()
{
    int n;
    struct Node* head;
    printf("enter the total number of nodes: ");
    scanf("%d",&n);
    head = (struct Node*)(malloc(sizeof(struct Node)));
    printf("enter the value of node: ");
    scanf("%d",&head->data);
    head->next = NULL;
    struct Node* current = head;
    for(int i=2;i<=n;i++)
    {
        struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
        printf("enter %d node value: ",i);
        scanf("%d",&newNode->data);
        current->next = newNode;
        current = newNode;
    }
    LinkedListTraversal(head);

}