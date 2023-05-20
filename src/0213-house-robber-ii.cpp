// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int N = nums.size();
    if (N == 0)
      return 0;
    if (N == 1)
      return nums[0];
    vector<int> dp(N + 1);
    dp[N] = 0;
    for (int i = N - 1; i >= 0; --i) {
      dp[i] = max(dp[i + 1], nums[i] + (i + 2 <= N ? dp[i + 2] : 0));
    }
    int best = dp[1];
    dp.assign(N, 0);
    dp[N] = dp[N - 1] = 0;
    for (int i = N - 2; i >= 0; --i) {
      dp[i] = max(dp[i + 1], nums[i] + (i + 2 <= N ? dp[i + 2] : 0));
    }
    best = max(best, dp[0]);
    return best;
  }
};
