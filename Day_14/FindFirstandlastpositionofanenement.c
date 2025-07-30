// Problem number 34 Find First and Last Position of Element in Sorted Array

#include <stdio.h>
#include <stdlib.h>  // ✅ Needed for malloc() and free()

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;

  int* result = (int*)malloc(2 * sizeof(int));
  result[0] = -1;
  result[1] = -1;

  if (numsSize == 0) {
    return result;
  }

  int left = 0;
  int right = numsSize - 1;

  // Find first occurrence
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  if (left >= numsSize || nums[left] != target) {
    return result;
  }

  result[0] = left;

  // Find last occurrence
  left = 0;
  right = numsSize - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] <= target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  result[1] = right;

  return result;
}

int main() {
  int numsSize;
  printf("Enter the number of elements: ");
  scanf("%d", &numsSize);

  int* nums = (int*)malloc(numsSize * sizeof(int));
  printf("Enter the array elements:\n");
  for (int i = 0; i < numsSize; i++) {
    scanf("%d", &nums[i]);
  }

  int target;
  printf("Enter the target: ");
  scanf("%d", &target);

  int returnSize;
  int* result = searchRange(nums, numsSize, target, &returnSize);

  printf("[%d, %d]\n", result[0], result[1]);

  free(result);
  free(nums);

  return 0;
}
