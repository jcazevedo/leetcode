class Solution {
public:
  int arrangeCoins(int n) {
    long long curr = 0, level = 0, next = 1;
    while (curr <= n) {
      curr += next;
      next += 1;
      level++;
    }
    return level - 1;
  }
};
