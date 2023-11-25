// 1480. Running Sum of 1d Array
// https://leetcode.com/problems/running-sum-of-1d-array/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> ans = vector<int>(nums.size(), 0);
    ans[0] = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) ans[i] = ans[i - 1] + nums[i];
    return ans;
  }
};
