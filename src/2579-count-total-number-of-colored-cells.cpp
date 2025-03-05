// 2579. Count Total Number of Colored Cells
// https://leetcode.com/problems/count-total-number-of-colored-cells/

class Solution {
 public:
  long long coloredCells(int n) {
    long long ans = 2 * n - 1;
    for (int i = 2 * n - 3; i > 0; i -= 2) { ans += 2 * i; }
    return ans;
  }
};
