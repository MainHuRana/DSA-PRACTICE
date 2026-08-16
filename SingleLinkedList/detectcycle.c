#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int detect_cycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(3);
    head1->next->next = newNode(4);
    head1->next->next->next = head1->next;

    if (detect_cycle(head1)) {
        printf("Example 1: Cycle detected\n");
    } else {
        printf("Example 1: Cycle not detected\n");
    }

    struct Node* head2 = newNode(1);
    head2->next = newNode(8);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    head2->next->next->next->next = NULL;

    if (detect_cycle(head2)) {
        printf("Example 2: Cycle detected\n");
    } else {
        printf("Example 2: Cycle not detected\n");
    }

    return 0;
}