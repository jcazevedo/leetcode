// 1482. Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (((long long)m) * k > n) return -1;
    int lo = 1;
    int hi = 1000000000;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int cnt = 0, curr = 0;
      for (int i = 0; i < n && cnt < m; ++i) {
        if (bloomDay[i] > mid)
          curr = 0;
        else
          ++curr;
        if (curr >= k) {
          ++cnt;
          curr = 0;
        }
      }
      if (cnt >= m)
        hi = mid;
      else
        lo = mid + 1;
    }
    return lo;
  }
};
