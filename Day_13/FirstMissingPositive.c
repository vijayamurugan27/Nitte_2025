// Problem number 41 First Missing Positive

#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    // Place nums[i] at its correct index if it's in range
    while (nums[i] > 0 && nums[i] <= numsSize && nums[nums[i] - 1] != nums[i]) {
      int temp = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = temp;
    }
  }

  // Find the first index i where nums[i] != i + 1
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }

  return numsSize + 1;
}

int main() {
  int numsSize;
  printf("Enter the number of elements: ");
  scanf("%d", &numsSize);

  int* nums = (int*)malloc(numsSize * sizeof(int));
  if (!nums) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  printf("Enter the array elements:\n");
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  int result = firstMissingPositive(nums, numsSize);
  printf("The smallest missing positive integer is: %d\n", result);

  free(nums);
  return 0;
}
