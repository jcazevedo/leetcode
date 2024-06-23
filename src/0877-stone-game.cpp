// 877. Stone Game
// https://leetcode.com/problems/stone-game/

#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 510

class Solution {
 private:
  // dp[i][j][p] refers to the score of the first player in case there are piles
  // between i and j available and it's player p turn to play.
  int dp[MAXN][MAXN][2];

 public:
  bool stoneGame(vector<int>& piles) {
    memset(dp, -1, sizeof(dp));
    int N = piles.size();
    int sum = 0;
    for (int i = 0; i < N; ++i) sum += piles[i];
    for (int i = 0; i <= N; ++i) dp[i][i][0] = dp[i][i][1] = 0;
    for (int l = 1; l <= N; ++l) {
      for (int i = 0; i < N && i + l <= N; ++i) {
        int j = i + l;
        dp[i][j][0] = max(piles[i] + dp[i + 1][j][1], piles[j - 1] + dp[i][j - 1][1]);
        dp[i][j][1] = min(dp[i + 1][j][0], dp[i][j - 1][0]);
      }
    }
    return 2 * dp[0][N][0] > sum;
  }
};
