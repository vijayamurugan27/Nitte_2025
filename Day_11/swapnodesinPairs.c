#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new ListNode
ListNode* createNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to swap pairs of nodes in the linked list
ListNode* swapPairs(ListNode* head) {
    // Base case: If the list is empty or only has one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Swap the first two nodes
    ListNode* second = head->next;
    head->next = swapPairs(second->next);
    second->next = head;

    // Return the new head of the swapped pair
    return second;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example 1: [1,2,3,4]
    ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(4);

    printf("Example 1: ");
    printf("Input: ");
    printList(head1);
    head1 = swapPairs(head1);
    printf("Output: ");
    printList(head1);

    // Example 2: []
    ListNode* head2 = NULL;

    printf("\nExample 2: ");
    printf("Input: ");
    printList(head2);
    head2 = swapPairs(head2);
    printf("Output: ");
    printList(head2);

    // Example 3: [1]
    ListNode* head3 = createNode(1);

    printf("\nExample 3: ");
    printf("Input: ");
    printList(head3);
    head3 = swapPairs(head3);
    printf("Output: ");
    printList(head3);

    // Example 4: [1,2,3]
    ListNode* head4 = createNode(1);
    head4->next = createNode(2);
    head4->next->next = createNode(3);

    printf("\nExample 4: ");
    printf("Input: ");
    printList(head4);
    head4 = swapPairs(head4);
    printf("Output: ");
    printList(head4);

    return 0;
}