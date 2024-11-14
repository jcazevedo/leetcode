// 2064. Minimized Maximum of Products Distributed to Any Store
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int amount, vector<int>& quantities, int n) {
    int m = quantities.size();
    int j = 0;
    int curr = quantities[j];
    for (int i = 0; i < n; ++i) {
      if (curr <= amount) {
        ++j;
        if (j == m) {
          return true;
        } else {
          curr = quantities[j];
        }
      } else {
        curr -= amount;
      }
    }
    return false;
  }

 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int m = quantities.size();
    int lo = 0;
    int hi = quantities[0];
    for (int i = 1; i < m; ++i) { hi = max(hi, quantities[i]); }
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(mid, quantities, n)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
