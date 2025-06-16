// 2016. Maximum Difference Between Increasing Elements
// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumDifference(vector<int>& nums) {
    int n = nums.size(), ans = -1, max_v = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] < max_v) { ans = max(ans, max_v - nums[i]); }
      max_v = max(max_v, nums[i]);
    }
    return ans;
  }
};
