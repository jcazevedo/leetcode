// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int ans = 0, l = 0, sum = 0;
    for (int r = 0; r < (int)nums.size(); ++r) {
      sum += nums[r];
      while (l <= r && (sum - nums[l]) >= target) {
        sum -= nums[l];
        ++l;
      }
      if (sum >= target) ans = ans == 0 ? (r - l) + 1 : min(ans, (r - l) + 1);
    }
    return ans;
  }
};
