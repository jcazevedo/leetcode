// 3483. Unique 3-Digit Even Numbers
// https://leetcode.com/problems/unique-3-digit-even-numbers/

#include <vector>

using namespace std;

class Solution {
 public:
  int totalNumbers(vector<int>& digits) {
    vector<int> cnt(10, 0);
    for (int digit : digits) { ++cnt[digit]; }
    int ans = 0;
    for (int u = 0; u <= 8; u += 2) {
      if (cnt[u] == 0) { continue; }
      --cnt[u];
      int d1 = 0, d2 = 0, same = 0;
      for (int d = 0; d <= 9; ++d) {
        if (cnt[d] > 0) {
          ++d2;
          if (d != 0) { ++d1; }
        }
        if (d != 0 && cnt[d] == 1) { ++same; }
      }
      ans += d2 * d1 - same;
      ++cnt[u];
    }
    return ans;
  }
};
