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
struct Node* del_at_pos(struct Node* tail,int pos){
    struct Node* temp;
    struct Node* temp2;
    if(tail==NULL){
        return NULL;
    }
    if(tail->next ==tail){
    free(tail);
    tail = NULL;
    return tail;
    }
    temp = tail->next;
    while(pos>2){
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    temp2 = NULL;
    return tail;

}

int main() {
    struct Node* tail = firstNode(22);  // BUG FIX: removed redundant malloc
    tail = add_at_end(tail, 33);
    tail = add_at_end(tail, 44);

    printf("Before deletion: ");
    display(tail);
    tail = CountNodes(tail);
   

    return 0;
}