// problem number 31 Next Permutation


#include <stdio.h>

// Swap utility
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Reverse a subarray from index start to end
void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Step 1: Find first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find element just larger than nums[i] from the end
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        // Step 3: Swap nums[i] and nums[j]
        swap(&nums[i], &nums[j]);
    }

    // Step 4: Reverse the subarray after index i
    reverse(nums, i + 1, numsSize - 1);
}

int main() {
    int nums[100], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    nextPermutation(nums, n);

    printf("Next permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
