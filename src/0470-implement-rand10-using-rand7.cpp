// 470. Implement Rand10() Using Rand7()
// https://leetcode.com/problems/implement-rand10-using-rand7/

#include <cstdlib>

class Solution {
private:
  int rand7() { return rand() % 7 + 1; }

public:
  int rand10() {
    int ans = 0;
    for (int i = 0; i < 10; ++i)
      ans += (rand7() - 1);
    return ans % 10 + 1;
  }
};
