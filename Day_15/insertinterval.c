// problem no 57: Insert Interval

#include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

// Define a struct for interval
typedef struct Interval {
  int start;
  int end;
} Interval;

// Comparison function for sorting intervals
int compare(const void* a, const void* b) {
  return ((Interval*)a)->start - ((Interval*)b)->start;
}

Interval* merge(Interval* intervals, int intervalsSize) {
  // Sort the intervals
  qsort(intervals, intervalsSize, sizeof(Interval), compare);

  Interval* res = (Interval*)malloc(intervalsSize * sizeof(Interval));
  int resSize = 0;

  res[resSize++] = intervals[0];

  for (int i = 1; i < intervalsSize; i++) {
    if (res[resSize - 1].end >= intervals[i].start) {
      res[resSize - 1].end = (res[resSize - 1].end > intervals[i].end) ? res[resSize - 1].end : intervals[i].end;
    } else {
      res[resSize++] = intervals[i];
    }
  }

  // Reallocate memory for res
  res = realloc(res, resSize * sizeof(Interval));

  for (int i = 0; i < resSize; i++) {
    printf("[%d, %d] ", res[i].start, res[i].end);
  }

  return res;
}

int main() {
  int n;
  printf("Enter the number of intervals: ");
  scanf("%d", &n);

  Interval* intervals = (Interval*)malloc(n * sizeof(Interval));

  for (int i = 0; i < n; i++) {
    printf("Enter interval %d: ", i + 1);
    scanf("%d %d", &intervals[i].start, &intervals[i].end);
  }

  Interval* res = merge(intervals, n);

  return 0;
}