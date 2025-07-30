// Problem 19 Remove nth node from End of the list

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
  dummy->val = 0;
  dummy->next = head;

  ListNode* first = dummy;
  ListNode* second = dummy;

  // Move the second pointer n steps ahead
  for (int i = 0; i <= n; i++) {
    second = second->next;
  }

  // Move both pointers until the second pointer reaches the end
  while (second) {
    first = first->next;
    second = second->next;
  }

  // Remove the nth node from the end
  ListNode* temp = first->next;
  first->next = first->next->next;

  free(temp);
  ListNode* result = dummy->next;
  free(dummy);

  return result;
}

int main() {
  ListNode* head = (ListNode*)malloc(sizeof(ListNode));
  head->val = 1;
  head->next = (ListNode*)malloc(sizeof(ListNode));
  head->next->val = 2;
  head->next->next = (ListNode*)malloc(sizeof(ListNode));
  head->next->next->val = 3;
  head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
  head->next->next->next->val = 4;
  head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
  head->next->next->next->next->val = 5;

  head = removeNthFromEnd(head, 2);

  // Print the linked list
  while (head) {
    printf("%d ", head->val);
    ListNode* temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}