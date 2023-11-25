// 1406. Stone Game III
// https://leetcode.com/problems/stone-game-iii/

#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int getAliceScoreAux(int player, int startAt, const vector<int>& stoneValue,
                       vector<vector<int>>& cache) {
    if (startAt >= (int)stoneValue.size())
      return 0;
    if (cache[player][startAt] == -1) {
      int ans =
          player == 0 ? numeric_limits<int>::min() : numeric_limits<int>::max();
      int sumSoFar = 0;
      for (int i = startAt; i < min(startAt + 3, (int)stoneValue.size()); ++i) {
        sumSoFar += stoneValue[i];
        if (player == 0)
          ans = max(ans, sumSoFar + getAliceScoreAux(player ^ 1, i + 1,
                                                     stoneValue, cache));
        else
          ans =
              min(ans, getAliceScoreAux(player ^ 1, i + 1, stoneValue, cache));
      }
      cache[player][startAt] = ans;
    }
    return cache[player][startAt];
  }

  int getAliceScore(const vector<int>& stoneValue) {
    vector<vector<int>> cache =
        vector<vector<int>>(2, vector<int>(stoneValue.size(), -1));
    return getAliceScoreAux(0, 0, stoneValue, cache);
  }

public:
  string stoneGameIII(vector<int>& stoneValue) {
    int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
    int aliceScore = getAliceScore(stoneValue);
    if (totalScore - aliceScore == aliceScore)
      return "Tie";
    if (totalScore - aliceScore > aliceScore)
      return "Bob";
    return "Alice";
  }
};
