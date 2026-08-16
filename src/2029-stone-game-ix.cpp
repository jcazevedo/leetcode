// 2029. Stone Game IX
// https://leetcode.com/problems/stone-game-ix/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    vector<int> mod = {0, 0, 0};
    for (int stone : stones) { ++mod[stone % 3]; }
    if (mod[0] % 2 == 0) { return mod[1] > 0 && mod[2] > 0; }
    return abs(mod[1] - mod[2]) > 2;
  }
};
