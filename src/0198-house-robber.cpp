// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int N = nums.size();
    if (N == 0) return 0;
    vector<int> dp(N, 0);
    dp[0] = nums[0];
    for (int i = 1; i < N; ++i) {
      dp[i] = max(dp[i - 1], nums[i]);
      if (i - 2 >= 0) dp[i] = max(dp[i], dp[i - 2] + nums[i]);
    }
    return dp[N - 1];
  }
};
