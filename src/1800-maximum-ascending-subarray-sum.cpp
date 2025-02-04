// 1800. Maximum Ascending Subarray Sum
// https://leetcode.com/problems/maximum-ascending-subarray-sum/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    int curr = nums[0];
    for (int i = 1; i < n; ++i) {
      if (nums[i] <= nums[i - 1]) { curr = 0; }
      curr += nums[i];
      ans = max(ans, curr);
    }
    return ans;
  }
};
