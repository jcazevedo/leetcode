// 1518. Water Bottles
// https://leetcode.com/problems/water-bottles/

class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0, full = numBottles, empty = 0;
    while (full) {
      ans += full;
      empty += full;
      full = empty / numExchange;
      empty -= full * numExchange;
    }
    return ans;
  }
};
