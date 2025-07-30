#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

typedef struct MinHeapNode {
  int val;
  ListNode* node;
} MinHeapNode;

typedef struct MinHeap {
  MinHeapNode** array;
  int size;
  int capacity;
} MinHeap;

// Function to create a new heap node
MinHeapNode* createMinHeapNode(int val, ListNode* node) {
  MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
  if (!newNode) {
    printf("Memory error\n");
    return NULL;
  }
  newNode->val = val;
  newNode->node = node;
  return newNode;
}

// Function to create a min heap
MinHeap* createMinHeap(int capacity) {
  MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
  if (!heap) {
    printf("Memory error\n");
    return NULL;
  }
  heap->array = (MinHeapNode**)malloc(sizeof(MinHeapNode*) * capacity);
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

// Swap heap nodes
void swapMinHeapNodes(MinHeapNode** a, MinHeapNode** b) {
  MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// Heapify the heap at index
void heapifyMin(MinHeap* heap, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < heap->size && heap->array[left]->val < heap->array[smallest]->val) {
    smallest = left;
  }

  if (right < heap->size && heap->array[right]->val < heap->array[smallest]->val) {
    smallest = right;
  }

  if (smallest != index) {
    swapMinHeapNodes(&heap->array[index], &heap->array[smallest]);
    heapifyMin(heap, smallest);
  }
}

// Extract the min node from heap
MinHeapNode* extractMin(MinHeap* heap) {
  if (heap->size == 0) {
    return NULL;
  }

  MinHeapNode* root = heap->array[0];
  heap->array[0] = heap->array[heap->size - 1];
  heap->size--;
  heapifyMin(heap, 0);
  return root;
}

// Insert a node into the heap
void insertMinHeapNode(MinHeap* heap, MinHeapNode* node) {
  if (heap->size == heap->capacity) {
    printf("Heap is full\n");
    return;
  }

  heap->array[heap->size] = node;
  int index = heap->size;
  heap->size++;

  while (index != 0 && heap->array[(index - 1) / 2]->val > heap->array[index]->val) {
    swapMinHeapNodes(&heap->array[(index - 1) / 2], &heap->array[index]);
    index = (index - 1) / 2;
  }
}

// Merge k sorted linked lists
ListNode* mergeKLists(ListNode** lists, int k) {
  MinHeap* heap = createMinHeap(k);

  for (int i = 0; i < k; i++) {
    if (lists[i]) {
      insertMinHeapNode(heap, createMinHeapNode(lists[i]->val, lists[i]));
    }
  }

  ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
  dummy->val = 0;
  dummy->next = NULL;
  ListNode* curr = dummy;

  while (heap->size > 0) {
    MinHeapNode* root = extractMin(heap);
    curr->next = root->node;
    curr = curr->next;

    if (root->node->next) {
      insertMinHeapNode(heap, createMinHeapNode(root->node->next->val, root->node->next));
    }

    free(root);
  }

  ListNode* head = dummy->next;
  free(dummy);
  free(heap->array);
  free(heap);

  return head;
}

int main() {
  int k;
  printf("Enter the number of linked lists: ");
  scanf("%d", &k);

  ListNode** lists = (ListNode**)malloc(sizeof(ListNode*) * k);

  for (int i = 0; i < k; i++) {
    int n;
    printf("Enter the number of nodes in linked list %d: ", i + 1);
    scanf("%d", &n);
    printf("Enter the node values in sorted order:\n");

    ListNode* head = NULL;
    ListNode* curr = NULL;
    for (int j = 0; j < n; j++) {
      int val;
      scanf("%d", &val);
      ListNode* node = (ListNode*)malloc(sizeof(ListNode));
      node->val = val;
      node->next = NULL;
      if (!head) {
        head = node;
        curr = node;
      } else {
        curr->next = node;
        curr = node;
      }
    }
    lists[i] = head;
  }

  ListNode* mergedHead = mergeKLists(lists, k);

  printf("Merged List: ");
  while (mergedHead) {
    printf("%d ", mergedHead->val);
    ListNode* temp = mergedHead;
    mergedHead = mergedHead->next;
    free(temp);
  }
  printf("\n");

  free(lists);
  return 0;
}
