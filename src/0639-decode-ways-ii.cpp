// 639. Decode Ways II
// https://leetcode.com/problems/decode-ways-ii/

#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int numDecodings(string s) {
    int N = s.size();
    vector<long long> dp(N + 1, 0);
    dp[N] = 1;
    for (int i = N - 1; i >= 0; --i) {
      long long one = 0, two = 0;
      if (s[i] == '*') {
        one = 9;
      } else if (s[i] != '0') {
        one = 1;
      }
      if (i + 2 <= N) {
        char a = s[i], b = s[i + 1];
        if (a == '1') {
          two = (b == '*') ? 9 : 1;
        } else if (a == '2') {
          if (b == '*') {
            two = 6;
          } else if (b >= '0' && b <= '6') {
            two = 1;
          }
        } else if (a == '*') {
          if (b == '*') {
            two = 15;
          } else if (b >= '0' && b <= '6') {
            two = 2;
          } else {
            two = 1;
          }
        }
      }
      dp[i] = (one * dp[i + 1]) % MOD;
      if (i + 2 <= N) { dp[i] = (dp[i] + two * dp[i + 2]) % MOD; }
    }
    return dp[0];
  }
};
