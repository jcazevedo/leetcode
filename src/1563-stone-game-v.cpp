// 1563. Stone Game V
// https://leetcode.com/problems/stone-game-v/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int bestScore(int l, int r, const vector<int>& pSum, const vector<int>& stoneValue, vector<vector<int>>& cache) {
    if (l == r) { return 0; }
    if (cache[l][r] != -1) { return cache[l][r]; }
    int best = 0;
    int tot = pSum[r];
    if (l != 0) { tot -= pSum[l - 1]; }
    int totL = stoneValue[l];
    int totR = tot - stoneValue[l];
    for (int m = l + 1; m <= r; ++m) {
      int leftScore = bestScore(l, m - 1, pSum, stoneValue, cache);
      int rightScore = bestScore(m, r, pSum, stoneValue, cache);
      if (totL < totR) {
        best = max(best, totL + leftScore);
      } else if (totR < totL) {
        best = max(best, totR + rightScore);
      } else {
        best = max(best, totL + max(leftScore, rightScore));
      }
      totL += stoneValue[m];
      totR -= stoneValue[m];
    }
    cache[l][r] = best;
    return best;
  }

 public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> pSum(n);
    pSum[0] = stoneValue[0];
    for (int i = 1; i < n; ++i) { pSum[i] = pSum[i - 1] + stoneValue[i]; }
    vector<vector<int>> cache = vector<vector<int>>(n, vector<int>(n, -1));
    return bestScore(0, n - 1, pSum, stoneValue, cache);
  }
};
