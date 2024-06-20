// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/

#include <vector>

using namespace std;

class Solution {
 private:
  int solve(int r, int n, vector<bool>& c, vector<bool>& d1, vector<bool>& d2) {
    if (r == n) return 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (!c[i] && !d1[i - r + n - 1] && !d2[i + r]) {
        c[i] = d1[i - r + n - 1] = d2[i + r] = true;
        ans += solve(r + 1, n, c, d1, d2);
        c[i] = d1[i - r + n - 1] = d2[i + r] = false;
      }
    return ans;
  }

 public:
  int totalNQueens(int n) {
    vector<bool> c(n, false);
    vector<bool> d1(2 * n - 1, false);
    vector<bool> d2(2 * n - 1, false);
    return solve(0, n, c, d1, d2);
  }
};
