#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
 int i, j;
 int swapped;
 for (i =0; i < n -1; i++) {
 swapped =0;
 for (j =0; j < n - i -1; j++) {
 if (arr[j] > arr[j +1]) {
 int temp = arr[j];
 arr[j] = arr[j +1];
 arr[j +1] = temp;
 swapped =1;
 }
 }
 if (!swapped) {
 break;
 }
 }
}

// Function to perform Binary Search
void BinarySearch(int arr[], int n, int x) {
 int l =0, r = n -1, mid;
 while (l <= r) {
 mid = l + (r - l) /2;
 if (arr[mid] == x) {
 printf("Element found at index %d\n", mid);
 return;
 } else if (arr[mid] < x) {
 l = mid +1;
 } else {
 r = mid -1;
 }
 }
 printf("Element not found\n");
}

int main() {
 int n, i;

 // Get the size of the array from the user
 printf("Enter the size of the array: ");
 scanf("%d", &n);

 // Create an array of the specified size
 int arr[n];

 // Get the array elements from the user
 printf("Enter %d elements:\n", n);
 for (i =0; i < n; i++) {
 scanf("%d", &arr[i]);
 }

 // Print the original array
 printf("Original array: ");
 for (i =0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");

 // Perform Bubble Sort
 bubbleSort(arr, n);

 // Print the sorted array
 printf("Sorted array: ");
 for (i =0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");

 // Get the element to search for from the user
 int key;
 printf("Enter the element to search for: ");
 scanf("%d", &key);

 // Perform Binary Search
 BinarySearch(arr, n, key);

 return 0;
}