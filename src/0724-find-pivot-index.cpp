// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/

#include <vector>

using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int left = 0;
    int right = 0;
    for (int num : nums) { right += num; }
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      right -= nums[i];
      if (left == right) { return i; }
      left += nums[i];
    }
    return -1;
  }
};
