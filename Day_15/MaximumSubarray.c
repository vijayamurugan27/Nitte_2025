// Problem number 53 Maximum sub array

// Problem number 53: Maximum Subarray using Divide and Conquer

#include <stdio.h>
#include <stdlib.h>  // ✅ Required for malloc and free

int maxCrossingSum(int* nums, int left, int mid, int right) {
  int leftSum = -100000;
  int sum = 0;
  for (int i = mid; i >= left; i--) {
    sum += nums[i];
    if (sum > leftSum) {
      leftSum = sum;
    }
  }

  int rightSum = -100000;
  sum = 0;
  for (int i = mid + 1; i <= right; i++) {
    sum += nums[i];
    if (sum > rightSum) {
      rightSum = sum;
    }
  }

  return leftSum + rightSum;
}

int maxSubarraySum(int* nums, int left, int right) {
  if (left == right) {
    return nums[left];
  }

  int mid = left + (right - left) / 2;

  int leftSum = maxSubarraySum(nums, left, mid);
  int rightSum = maxSubarraySum(nums, mid + 1, right);
  int crossSum = maxCrossingSum(nums, left, mid, right);

  if (leftSum >= rightSum && leftSum >= crossSum) {
    return leftSum;
  } else if (rightSum >= leftSum && rightSum >= crossSum) {
    return rightSum;
  } else {
    return crossSum;
  }
}

int maxSubArray(int* nums, int numsSize) {
  return maxSubarraySum(nums, 0, numsSize - 1);
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

  int maxSum = maxSubArray(nums, numsSize);
  printf("The maximum subarray sum is: %d\n", maxSum);

  free(nums);
  return 0;
}
