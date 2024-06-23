// 935. Knight Dialer
// https://leetcode.com/problems/knight-dialer/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  static vector<vector<int>> prev;

 public:
  int knightDialer(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(10, 0));
    for (int i = 0; i < 10; ++i) { dp[1][i] = 1; }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k : prev[j]) { dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD; }
      }
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i) { ans = (ans + dp[n][i]) % MOD; }
    return ans;
  }
};

vector<vector<int>> Solution::prev = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
