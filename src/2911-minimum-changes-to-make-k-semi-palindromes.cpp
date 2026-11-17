// 2911. Minimum Changes to Make K Semi-palindromes
// https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumChanges(string s, int k) {
    int n = s.size();
    vector<vector<int>> cost(n, vector<int>(n, n));
    for (int len = 2; len <= n; ++len) {
      for (int d = 1; d < len; ++d) {
        if (len % d != 0) { continue; }
        for (int start = 0; start + len <= n; ++start) {
          int changes = 0;
          for (int offset = 0; offset < d; ++offset) {
            int left = start + offset;
            int right = start + len - d + offset;
            while (left < right) {
              changes += s[left] != s[right];
              left += d;
              right -= d;
            }
          }
          cost[start][start + len - 1] = min(cost[start][start + len - 1], changes);
        }
      }
    }
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, n));
    dp[0][0] = 0;
    for (int parts = 1; parts <= k; ++parts) {
      for (int end = 2 * parts; end <= n; ++end) {
        for (int start = 2 * (parts - 1); start <= end - 2; ++start) {
          dp[parts][end] = min(dp[parts][end], dp[parts - 1][start] + cost[start][end - 1]);
        }
      }
    }
    return dp[k][n];
  }
};
