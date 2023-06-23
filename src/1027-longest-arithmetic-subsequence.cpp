// 1027. Longest Arithmetic Subsequence
// https://leetcode.com/problems/longest-arithmetic-subsequence/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int ans = 0, N = nums.size();
    vector<unordered_map<int, int>> dp = vector<unordered_map<int, int>>(N, unordered_map<int, int>());
    for (int j = 0; j < N; ++j) {
      for (int i = 0; i < j; ++i) {
        int diff = nums[i] - nums[j];
        dp[j][diff] = (dp[i].count(diff) ? dp[i][diff] : 1) + 1;
        ans = max(ans, dp[j][diff]);
      }
    }
    return ans;
  }
};
