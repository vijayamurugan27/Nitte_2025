#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int k = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }

    return k;
}

int main() {
    int numsSize;
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    if (numsSize <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int* nums = (int*)malloc(numsSize * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < numsSize; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    // Sort the array first
    qsort(nums, numsSize, sizeof(int), compare);

    int k = removeDuplicates(nums, numsSize);

    printf("\nNumber of unique elements: %d\n", k);
    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    free(nums);
    return 0;
}
