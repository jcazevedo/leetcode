// 494. Target Sum
// https://leetcode.com/problems/target-sum/

#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAXN 20000

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int N = nums.size();
    int dp[N + 1][MAXN * 2 + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][MAXN] = 1;
    for (int i = 1; i <= N; ++i) {
      int num = nums[i - 1];
      for (int j = 0; j <= MAXN * 2; ++j) {
        if (j - num >= 0) dp[i][j] += dp[i - 1][j - num];
        if (j + num <= MAXN * 2) dp[i][j] += dp[i - 1][j + num];
      }
    }
    return dp[N][target + MAXN];
  }
};
