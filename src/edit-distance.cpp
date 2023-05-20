#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int N = word1.size();
    int M = word2.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    for (int n = 0; n <= N; ++n) {
      for (int m = 0; m <= M; ++m) {
        if (n == 0)
          dp[n][m] = m;
        else if (m == 0)
          dp[n][m] = n;
        else if (word1[n - 1] == word2[m - 1])
          dp[n][m] = dp[n - 1][m - 1];
        else
          dp[n][m] = 1 + min(dp[n][m - 1], min(dp[n - 1][m], dp[n - 1][m - 1]));
      }
    }
    return dp[N][M];
  }
};
