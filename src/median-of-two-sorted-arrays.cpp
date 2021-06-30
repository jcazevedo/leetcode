#include <vector>

using namespace std;

class Solution {
private:
  double go(int i, vector<int> &nums1, int i1, vector<int> &nums2, int i2) {
    if (i1 >= nums1.size())
      return nums2[i2 + i];
    if (i2 >= nums2.size())
      return nums1[i1 + i];
    if (i == 0)
      return min(nums1[i1], nums2[i2]);
    int m1 = i1 + i / 2;
    int m2 = i2 + i / 2;
    int v1 = m1 < nums1.size() ? nums1[m1] : numeric_limits<int>::max();
    int v2 = m2 < nums2.size() ? nums2[m2] : numeric_limits<int>::max();
    if (v1 < v2) {
      return go(i - (i + 1) / 2, nums1, i1 + (i + 1) / 2, nums2, i2);
    } else {
      return go(i - (i + 1) / 2, nums1, i1, nums2, i2 + (i + 1) / 2);
    }
  }

public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int N1 = nums1.size(), N2 = nums2.size();
    int N = N1 + N2;
    if (N % 2 == 0)
      return (go(N / 2 - 1, nums1, 0, nums2, 0) + go(N / 2, nums1, 0, nums2, 0)) / 2.0;
    return go(N / 2, nums1, 0, nums2, 0);
  }
};
