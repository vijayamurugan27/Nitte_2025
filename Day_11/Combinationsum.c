// Problem 18 4Sum

#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void fourSum(int* nums, int numsSize, int target) {
  // Sort the array
  qsort(nums, numsSize, sizeof(int), compare);

  for (int i = 0; i < numsSize - 3; i++) {
    // Skip duplicates
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    for (int j = i + 1; j < numsSize - 2; j++) {
      // Skip duplicates
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }

      int left = j + 1;
      int right = numsSize - 1;

      while (left < right) {
        int sum = nums[i] + nums[j] + nums[left] + nums[right];

        if (sum < target) {
          left++;
        } else if (sum > target) {
          right--;
        } else {
          printf("[%d, %d, %d, %d]\n", nums[i], nums[j], nums[left], nums[right]);

          // Skip duplicates
          while (left < right && nums[left] == nums[left + 1]) {
            left++;
          }

          // Skip duplicates
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }

          left++;
          right--;
        }
      }
    }
  }
}

int main() {
  int nums[] = {1, 0, -1, 0, -2, 2};
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int target = 0;

  fourSum(nums, numsSize, target);

  return 0;
}