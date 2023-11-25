// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> res(num + 1);
    for (int p = 0; p < 32; ++p) {
      int left = 1 << p;
      if (left > num) break;
      int right = min(1 << (p + 1), num + 1);
      for (int i = left; i < right; ++i) { res[i] = res[i - left] + 1; }
    }
    return res;
  }
};
