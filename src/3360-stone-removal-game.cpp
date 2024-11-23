// 3360. Stone Removal Game
// https://leetcode.com/problems/stone-removal-game/

class Solution {
 public:
  bool canAliceWin(int n) {
    int p = 0, rem = 10;
    while (n >= rem && rem > 0) {
      n -= rem;
      --rem;
      p ^= 1;
    }
    return p == 1;
  }
};
