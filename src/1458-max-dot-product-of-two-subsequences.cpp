// 1458. Max Dot Product of Two Subsequences
// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int N = nums1.size(), M = nums2.size();
    vector<vector<vector<int>>> dp(
        N + 1, vector<vector<int>>(M + 1, vector<int>(2, -1000000)));

    for (int i = 0; i <= N; ++i) dp[i][0][false] = 0;
    for (int j = 0; j <= M; ++j) dp[0][j][false] = 0;

    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        dp[i][j][true] = max(dp[i][j][true], dp[i - 1][j - 1][true]);
        dp[i][j][true] = max(dp[i][j][true], dp[i - 1][j][true]);
        dp[i][j][true] = max(dp[i][j][true], dp[i][j - 1][true]);
        dp[i][j][true] = max(dp[i][j][true], dp[i - 1][j - 1][false] +
                                                 nums1[i - 1] * nums2[j - 1]);
        dp[i][j][true] = max(dp[i][j][true], dp[i - 1][j - 1][true] +
                                                 nums1[i - 1] * nums2[j - 1]);

        dp[i][j][false] = max(dp[i][j][false], dp[i - 1][j - 1][false]);
        dp[i][j][false] = max(dp[i][j][false], dp[i - 1][j][false]);
        dp[i][j][false] = max(dp[i][j][false], dp[i][j - 1][false]);
      }
    }

    return dp[N][M][true];
  }
};
