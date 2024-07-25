// 912. Sort an Array
// https://leetcode.com/problems/sort-an-array/

#include <vector>

using namespace std;

class Solution {
 private:
  void merge(vector<int>& nums, int l, int m, int r) {
    int L = m - l + 1;
    int R = r - m;
    vector<int> left(L);
    vector<int> right(R);
    for (int i = 0; i < L; ++i) { left[i] = nums[l + i]; }
    for (int i = 0; i < R; ++i) { right[i] = nums[m + 1 + i]; }
    int i = 0, j = 0, k = l;
    while (i < L && j < R) {
      if (left[i] <= right[j]) {
        nums[k++] = left[i++];
      } else {
        nums[k++] = right[j++];
      }
    }
    while (i < L) { nums[k++] = left[i++]; }
    while (j < R) { nums[k++] = right[j++]; }
  }

  void mergeSort(vector<int>& nums, int l, int r) {
    if (l < r) {
      int m = l + (r - l) / 2;
      mergeSort(nums, l, m);
      mergeSort(nums, m + 1, r);
      merge(nums, l, m, r);
    }
  }

 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
