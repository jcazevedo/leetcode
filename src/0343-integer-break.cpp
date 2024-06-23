// 343. Integer Break
// https://leetcode.com/problems/integer-break/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int maxProd(int n, bool first, vector<vector<int>>& cache) {
    if (n == 1) return 1;
    if (cache[first][n] == -1) {
      if (!first) cache[first][n] = n;
      for (int i = 1; i < n; ++i) cache[first][n] = max(cache[first][n], maxProd(i, false, cache) * (n - i));
    }
    return cache[first][n];
  }

 public:
  int integerBreak(int n) {
    vector<vector<int>> cache(2, vector<int>(n + 1, -1));
    return maxProd(n, true, cache);
  }
};
