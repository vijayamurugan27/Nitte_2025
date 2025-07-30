// Problem number 56: Merge Intervals

#include <stdio.h>
#include <stdlib.h>

// Define a struct for interval
typedef struct Interval {
  int start;
  int end;
} Interval;

// Comparison function for sorting intervals
int compare(const void* a, const void* b) {
  return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Merge function now takes a pointer to result size
Interval* merge(Interval* intervals, int intervalsSize, int* returnSize) {
  if (intervalsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  qsort(intervals, intervalsSize, sizeof(Interval), compare);

  Interval* res = (Interval*)malloc(intervalsSize * sizeof(Interval));
  int resSize = 0;

  res[resSize++] = intervals[0];

  for (int i = 1; i < intervalsSize; i++) {
    if (res[resSize - 1].end >= intervals[i].start) {
      if (intervals[i].end > res[resSize - 1].end)
        res[resSize - 1].end = intervals[i].end;
    } else {
      res[resSize++] = intervals[i];
    }
  }

  res = realloc(res, resSize * sizeof(Interval));
  *returnSize = resSize;
  return res;
}

int main() {
  int n;
  printf("Enter the number of intervals: ");
  scanf("%d", &n);

  Interval* intervals = (Interval*)malloc(n * sizeof(Interval));

  for (int i = 0; i < n; i++) {
    printf("Enter interval %d (start end): ", i + 1);
    scanf("%d %d", &intervals[i].start, &intervals[i].end);
  }

  int mergedSize = 0;
  Interval* merged = merge(intervals, n, &mergedSize);

  printf("Merged intervals: ");
  for (int i = 0; i < mergedSize; i++) {
    printf("[%d, %d] ", merged[i].start, merged[i].end);
  }
  printf("\n");

  free(intervals);
  free(merged);

  return 0;
}
