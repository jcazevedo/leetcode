// 403. Frog Jump
// https://leetcode.com/problems/frog-jump/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  bool goodAux(int stone,
               int lastJump,
               const unordered_set<int>& positions,
               int lastStone,
               unordered_map<int, unordered_map<int, bool>>& cache) {
    if (stone == lastStone) return true;
    if (positions.find(stone) == positions.end()) return false;
    if (cache.find(stone) == cache.end() ||
        cache[stone].find(lastJump) == cache[stone].end()) {
      bool ans = false;
      if (!ans && lastJump - 1 > 0)
        ans = goodAux(stone + lastJump - 1, lastJump - 1, positions, lastStone,
                      cache);
      if (!ans && lastJump > 0)
        ans = goodAux(stone + lastJump, lastJump, positions, lastStone, cache);
      if (!ans)
        ans = goodAux(stone + lastJump + 1, lastJump + 1, positions, lastStone,
                      cache);
      cache[stone][lastJump] = ans;
    }
    return cache[stone][lastJump];
  }

  bool good(int stone,
            int lastJump,
            const unordered_set<int>& positions,
            int lastStone) {
    unordered_map<int, unordered_map<int, bool>> cache;
    return goodAux(stone, lastJump, positions, lastStone, cache);
  }

 public:
  bool canCross(vector<int>& stones) {
    unordered_set<int> positions;
    int lastStone = stones.back();
    for (int stone : stones) positions.insert(stone);
    return good(0, 0, positions, lastStone);
  }
};
