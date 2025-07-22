#include <stdio.h>

// Function to perform Cycle Sort
void cycleSort(int arr[], int n)
{
    int writes = 0;

    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++)
    {
        int item = arr[cycle_start];

        // Find the position where we put the item
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If the item is already in the correct position
        if (pos == cycle_start)
            continue;

        // Skip duplicates
        while (item == arr[pos])
            pos++;

        // Put the item to its right position
        if (pos != cycle_start)
        {
            int temp = item;
            item = arr[pos];
            arr[pos] = temp;
            writes++;
        }

        // Rotate rest of the cycle
        while (pos != cycle_start)
        {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            while (item == arr[pos])
                pos++;

            if (item != arr[pos])
            {
                int temp = item;
                item = arr[pos];
                arr[pos] = temp;
                writes++;
            }
        }
    }

    printf("Total memory writes: %d\n", writes);
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main()
{
    int arr[] = {5, 1, 4, 2, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    cycleSort(arr, n);

    printf("Sorted array:   ");
    printArray(arr, n);

    return 0;
}