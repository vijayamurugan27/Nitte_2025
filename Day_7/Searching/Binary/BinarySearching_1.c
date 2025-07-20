#include <stdio.h>

// Function to perform Binary Search
void BinarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("Element not found\n");
}

// Function to sort an array in ascending order
void sortArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    sortArray(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
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