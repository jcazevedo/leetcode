// 540. Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int N = nums.size();
    int lo = 0, hi = N - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int diff = mid - lo;
      if (diff % 2 != 0 && mid > 0 && nums[mid] == nums[mid - 1]) {
        lo = mid + 1;
      } else if (diff % 2 == 0 && mid < N - 1 && nums[mid] == nums[mid + 1]) {
        lo = mid + 2;
      } else {
        hi = mid - 1;
      }
    }
    return nums[lo];
  }
};
