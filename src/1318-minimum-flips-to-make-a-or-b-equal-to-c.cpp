// 1318. Minimum Flips to Make a OR b Equal to c
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
private:
  bool isSet(int num, int bit) { return num & (1 << bit); }

public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i < 30; ++i)
      if (isSet(c, i))
        ans += !isSet(a, i) && !isSet(b, i);
      else
        ans += isSet(a, i) + isSet(b, i);
    return ans;
  }
};
