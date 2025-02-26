// 1749. Maximum Absolute Sum of Any Subarray
// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int ans = 0, n = nums.size(), currp = 0, currn = 0;
    for (int i = 0; i < n; ++i) {
      currp = max(nums[i], currp + nums[i]);
      currn = max(-nums[i], currn - nums[i]);
      ans = max(ans, currp);
      ans = max(ans, currn);
    }
    return ans;
  }
};
