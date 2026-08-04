#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Circularlist(int data) {
    struct Node* temp;
    temp = (struct Node*)(malloc(sizeof(struct Node)));
    temp->data = data;
    temp->next = temp;
    return temp;
}
void printList(struct Node* tail) {
    struct Node* curr = tail->next;  // start from head (node after tail)
    do {
        printf("%d\n", curr->data);
        curr = curr->next;
    } while (curr != tail->next);    // stop when we reach head again
}


struct Node* add_at_beg(struct Node* tail, int data) {
    struct Node* newP;
    newP = (struct Node*)(malloc(sizeof(struct Node)));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}

int main() {
    struct Node* tail;
    tail = Circularlist(36);
    tail = add_at_beg(tail, 46);
    printList(tail);
    return 0;
}