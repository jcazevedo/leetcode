#include <cstring>
#include <string>

using namespace std;

#define MAXN 2010

class Solution {
private:
  int N;
  string str;
  bool is_palindrome[MAXN][MAXN];
  int dp[MAXN];

  int go(int i) {
    if (i >= N)
      return 0;
    if (dp[i] == -1) {
      for (int j = i; j < N; ++j) {
        if (is_palindrome[i][j]) {
          int next = go(j + 1) + 1;
          if (dp[i] == -1 || next < dp[i])
            dp[i] = next;
        }
      }
    }
    return dp[i];
  }

public:
  int minCut(string s) {
    str = s;
    N = str.size();
    memset(is_palindrome, false, sizeof(is_palindrome));
    memset(dp, -1, sizeof(dp));
    for (int l = 1; l <= N; ++l) {
      for (int i = 0; i + l <= N; ++i) {
        int j = i + l - 1;
        if (l == 1)
          is_palindrome[i][j] = true;
        else if (l == 2)
          is_palindrome[i][j] = str[i] == str[j];
        else
          is_palindrome[i][j] = str[i] == str[j] && is_palindrome[i + 1][j - 1];
      }
    }
    return go(0) - 1;
  }
};
