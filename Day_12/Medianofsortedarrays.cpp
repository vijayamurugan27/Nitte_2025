#include <iostream>
#include <climits>  // For INT_MIN and INT_MAX
#include <algorithm> // For max() and min()

using namespace std;

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int low = 0, high = m;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return (double)max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    // This line should never be reached
    return -1.0;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    double median = findMedianSortedArrays(nums1, m, nums2, n);
    cout << "Median: " << median << endl;

    return 0;
}
