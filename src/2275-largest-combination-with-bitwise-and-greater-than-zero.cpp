// 2275. Largest Combination With Bitwise AND Greater Than Zero
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

#include <algorithm>
#include <vector>

using namespace std;

#define MAXBITS 24

class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    vector<int> cnt(MAXBITS, 0);
    for (int v : candidates) {
      int b = 0;
      while (v) {
        if (v % 2) { ++cnt[b]; }
        v /= 2;
        ++b;
      }
    }
    int ans = 1;
    for (int i = 0; i < MAXBITS; ++i) { ans = max(ans, cnt[i]); }
    return ans;
  }
};
