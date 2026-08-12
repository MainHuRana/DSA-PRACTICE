#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* toDelete = head;
        head = head->next;
        free(toDelete);
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* temp1 = head;
    struct ListNode* temp2 = temp1->next;
    while (temp2 != NULL) {
        if (temp2->val != val) {
            temp1 = temp2;
            temp2 = temp2->next;
        } else {
            temp1->next = temp2->next;
            free(temp2);
            temp2 = temp1->next;
        }
    }
    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(6);
    head->next = createNode(6);
    head->next->next = createNode(2);
    head->next->next->next = createNode(6);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(6);

    printf("Before: ");
    printList(head);

    head = removeElements(head, 6);

    printf("After:  ");
    printList(head);

    return 0;
}