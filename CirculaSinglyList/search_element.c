#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    int data;
};

struct Node* firstNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct Node* add_at_end(struct Node* tail, int data) {
    struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return newP;              // newP is the new tail
}

struct Node* add_at_pos(struct Node* tail, int data, int pos) {
    struct Node* newp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = tail->next;
    newp->data = data;
    int len = 1;
    struct Node* counter = tail->next;
    do { len++; counter = counter->next; } while (counter != tail->next);
    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        free(newp);
        return tail;
    }
    while (pos > 1) {
        p = p->next;
        pos--;
    }
    newp->next = p->next;
    p->next = newp;
    if (p == tail) tail = newp;  // inserted after tail = new tail
    return tail;
}

void display(struct Node* tail) {
    if (tail == NULL) { printf("List is empty\n"); return; }
    struct Node* p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("\n");
}

struct Node* CountNodes(struct Node* tail){
    struct Node* temp;
    int count = 1;
    temp = tail->next;
    while(temp!=tail){
        count++;
        temp = temp->next;
    }
    printf("%d",count);
}

struct Node* circularLinkedList(struct Node* tail, int n, int data) {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n == 0) return NULL;
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    tail = firstNode(data);
    for (int i = 1; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }
    return tail;   // BUG FIX: was missing
}
int SearchElement(struct Node* tail){
    if(tail==NULL){
        return -2;
    }
    struct Node* temp = tail->next;
    int index = 0;
    int element = 33;
    do{
        if(temp->data == element){
        return index;
        }
        temp = temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
}

int main() {
    struct Node* tail = firstNode(22);  // BUG FIX: removed redundant malloc
    tail = add_at_end(tail, 33);
    tail = add_at_end(tail, 44);

   int result = SearchElement(tail);
if(result == -2) printf("List is empty\n");
else if(result == -1) printf("Element not found\n");
else printf("Element found at index: %d\n", result);
display(tail);
}