#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print a 2D array
void printTriplets(int **triplets, int size) {
    for (int i = 0; i < size; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", triplets[i][j]);
            if (j < 2) {
                printf(",");
            }
        }
        printf("]\n");
    }
}

// Function to find all unique triplets that sum up to zero
int **threeSum(int *nums, int numsSize, int *returnSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int **triplets = (int **)malloc(numsSize * sizeof(int *));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                // Found a triplet
                triplets[*returnSize] = (int *)malloc(3 * sizeof(int));
                triplets[*returnSize][0] = nums[i];
                triplets[*returnSize][1] = nums[left];
                triplets[*returnSize][2] = nums[right];
                (*returnSize)++;

                // Skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }
        }
    }

    return triplets;
}

int main() {
    int numsSize;
    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);

    int *nums = (int *)malloc(numsSize * sizeof(int));
    printf("Enter %d elements: ", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int returnSize;
    int **triplets = threeSum(nums, numsSize, &returnSize);

    if (returnSize == 0) {
        printf("No triplets found that sum up to zero.\n");
    } else {
        printf("Triplets that sum up to zero:\n");
        printTriplets(triplets, returnSize);
    }

    for (int i = 0; i < returnSize; i++) {
        free(triplets[i]);
    }
    free(triplets);
    free(nums);

    return 0;
}