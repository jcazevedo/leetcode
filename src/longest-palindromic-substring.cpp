#include <cstring>
#include <string>

using namespace std;

#define MAXN 1000

class Solution {
private:
  int dp[MAXN][MAXN];
  int go(string & s, int l, int r) {
    if (dp[l][r] == -1) {
      if (s[l] != s[r]) {
        dp[l][r] = 0;
      } else {
        if (l == r)
          dp[l][r] = 1;
        else if (l + 1 == r)
          dp[l][r] = 2;
        else {
          int m = go(s, l + 1, r - 1);
          if (m != 0)
            dp[l][r] = 2 + m;
          else
            dp[l][r] = 0;
        }
      }
    }
    return dp[l][r];
  }

public:
  string longestPalindrome(string s) {
    memset(dp, -1, sizeof(dp));
    int N = s.size();
    int best = 0, l = -1, si = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 1; i + j <= N; j++) {
        int len = go(s, i, i + j - 1);
        if (len > best) {
          best = len;
          l = i;
          si = j;
        }
      }
    }
    return s.substr(l, si);
  }
};
