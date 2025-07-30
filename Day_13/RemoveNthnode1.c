// Problem 19 Remove nth node from End of the list


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
  if (!newNode) {
    printf("Memory error\n");
    return NULL;
  }
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

// Function to remove the nth node from the end
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
  int n;
  printf("Enter the number of elements in the list: ");
  scanf("%d", &n);

  ListNode* head = NULL;
  printf("Enter the list values: \n");
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    ListNode* newNode = createNode(val);
    if (head == NULL) {
      head = newNode;
    } else {
      ListNode* temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  printf("Original list: \n");
  printList(head);

  int pos;
  printf("Enter the position of the node to be removed from the end: ");
  scanf("%d", &pos);

  head = removeNthFromEnd(head, pos);

  printf("List after removing the node: \n");
  printList(head);

  // Free the allocated memory
  while (head) {
    ListNode* temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}