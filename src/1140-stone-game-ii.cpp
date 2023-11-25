// 1140. Stone Game II
// https://leetcode.com/problems/stone-game-ii/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

#define ALICE 0
#define BOB 1

class Solution {
private:
  int maxStonesAux(int player, int minStone, int M, vector<int>& piles,
                   vector<int>& sumUntil, vector<vector<vector<int>>>& cache) {
    if (minStone >= (int)piles.size())
      return 0;
    if (cache[player][minStone][M] == -1) {
      int ans = player == ALICE ? numeric_limits<int>::min()
                                : numeric_limits<int>::max();
      int prevSum = minStone == 0 ? 0 : sumUntil[minStone - 1];
      for (int i = minStone; i < min(minStone + 2 * M, (int)piles.size());
           ++i) {
        int stonesSum = sumUntil[i] - prevSum;
        if (player == ALICE)
          ans = max(ans, stonesSum + maxStonesAux(player ^ 1, i + 1,
                                                  max(M, i - minStone + 1),
                                                  piles, sumUntil, cache));
        else
          ans =
              min(ans, maxStonesAux(player ^ 1, i + 1, max(M, i - minStone + 1),
                                    piles, sumUntil, cache));
      }
      cache[player][minStone][M] = ans;
    }
    return cache[player][minStone][M];
  }

  int maxStones(vector<int>& piles) {
    vector<int> sumUntil = vector<int>(piles.size(), 0);
    sumUntil[0] = piles[0];
    for (int i = 1; i < (int)piles.size(); ++i)
      sumUntil[i] += (sumUntil[i - 1] + piles[i]);
    vector<vector<vector<int>>> cache = vector<vector<vector<int>>>(
        2, vector<vector<int>>(piles.size(),
                               vector<int>(piles.size() * 2 + 1, -1)));
    return maxStonesAux(ALICE, 0, 1, piles, sumUntil, cache);
  }

public:
  int stoneGameII(vector<int>& piles) { return maxStones(piles); }
};
