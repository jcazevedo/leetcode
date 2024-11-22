// 1072. Flip Columns For Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    map<vector<int>, int> cnt;
    int ans = 0;
    for (const vector<int>& line : matrix) {
      vector<int> cmp = vector<int>(line.size(), 0);
      int L = line.size(), curr = 0;
      for (int i = 0; i < L; ++i) {
        if (i > 0 && line[i] != line[i - 1]) { curr ^= 1; }
        cmp[i] = curr;
      }
      ++cnt[cmp];
      ans = max(ans, cnt[cmp]);
    }
    return ans;
  }
};
