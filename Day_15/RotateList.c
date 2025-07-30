#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to rotate the list to the right by k places
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Find the length and the tail
    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Make the list circular
    tail->next = head;

    // Find the new tail position
    k = k % length;
    int newTailIndex = length - k;
    ListNode* newTail = head;

    for (int i = 1; i < newTailIndex; i++) {
        newTail = newTail->next;
    }

    // New head is next of new tail
    ListNode* newHead = newTail->next;
    newTail->next = NULL; // Break the circle

    return newHead;
}

int main() {
    int n, k, val;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    ListNode *head = NULL, *tail = NULL;

    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        ListNode* newNode = createNode(val);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original list:\n");
    printList(head);

    printf("Enter the number of places to rotate: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated list:\n");
    printList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
