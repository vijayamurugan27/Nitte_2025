// problem number 53: Jump Game with Path Reconstruction

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printJumpPath(int* nums, int numsSize) {
    int* jumps = (int*)malloc(numsSize * sizeof(int));
    int* path = (int*)malloc(numsSize * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        jumps[i] = INT_MAX;
        path[i] = -1;
    }

    jumps[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (j + nums[j] >= i && jumps[j] + 1 < jumps[i]) {
                jumps[i] = jumps[j] + 1;
                path[i] = j;
            }
        }
    }

    if (jumps[numsSize - 1] == INT_MAX) {
        printf("Cannot reach the last index.\n");
        free(jumps);
        free(path);
        return;
    }

    printf("Minimum number of jumps: %d\n", jumps[numsSize - 1]);

    // Reconstruct path
    int stack[numsSize];
    int top = 0;
    int i = numsSize - 1;
    while (i >= 0) {
        stack[top++] = nums[i];
        i = path[i];
    }

    printf("Jump path: ");
    for (int j = top - 1; j >= 0; j--) {
        printf("%d", stack[j]);
        if (j != 0) printf(" -> ");
    }
    printf("\n");

    free(jumps);
    free(path);
}

int main() {
    int numsSize;
    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);

    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the array elements: \n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printJumpPath(nums, numsSize);

    free(nums);
    return 0;
}
