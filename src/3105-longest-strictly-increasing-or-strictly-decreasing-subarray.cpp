// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || nums[i] <= nums[i - 1]) { curr = 0; }
      ++curr;
      ans = max(ans, curr);
    }
    for (int i = 0; i < n; ++i) {
      if (i == 0 || nums[i] >= nums[i - 1]) { curr = 0; }
      ++curr;
      ans = max(ans, curr);
    }
    return ans;
  }
};
