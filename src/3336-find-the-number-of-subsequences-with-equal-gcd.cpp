// 3336. Find the Number of Subsequences With Equal GCD
// https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/

#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

 public:
  int subsequencePairCount(vector<int>& nums) {
    int n = nums.size(), m = *max_element(begin(nums), end(nums));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int v1 = 0; v1 <= m; ++v1) {
        for (int v2 = 0; v2 <= m; ++v2) {
          int pv1 = gcd(v1, nums[i - 1]);
          int pv2 = gcd(v2, nums[i - 1]);
          dp[i][pv1][v2] = (dp[i][pv1][v2] + dp[i - 1][v1][v2]) % MOD;
          dp[i][v1][pv2] = (dp[i][v1][pv2] + dp[i - 1][v1][v2]) % MOD;
          dp[i][v1][v2] = (dp[i][v1][v2] + dp[i - 1][v1][v2]) % MOD;
        }
      }
    }
    int ans = 0;
    for (int v = 1; v <= m; ++v) { ans = (ans + dp[n][v][v]) % MOD; }
    return ans;
  }
};
