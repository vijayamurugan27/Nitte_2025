#include <stdio.h>

// Function to perform Binary Search
void BinarySearch(int arr[], int n, int x) {
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            printf("Element found at index %d (in the sorted array)\n", mid);
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

    // Step 1: Take array input
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n], copy[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        copy[i] = arr[i]; // Save original for display
    }

    // Step 2: Show original array
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", copy[i]);
    }

    // Step 3: Sort and display sorted array
    sortArray(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 4: Start binary search loop
    while (1) {
        int key;
        char choice;

        // Ask user for the element to search
        printf("\nEnter the element to search for: ");
        scanf("%d", &key);

        // Perform binary search
        BinarySearch(arr, n, key);

        // Ask user whether to continue searching
        printf("Do you want to search another element? (y/n): ");
        scanf(" %c", &choice); // space before %c handles newline

        if (choice == 'n' || choice == 'N') {
            printf("Exiting search. Goodbye!\n");
            break;
        }
    }

    return 0;
}
