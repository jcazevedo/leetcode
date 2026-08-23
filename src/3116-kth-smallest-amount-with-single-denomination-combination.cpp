// 3116. Kth Smallest Amount With Single Denomination Combination
// https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  long long count(long long x, const vector<int>& coins) {
    int n = coins.size();
    long long result = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
      long long multiple = 1;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          multiple = multiple / gcd(multiple, coins[i]) * coins[i];
          if (multiple > x) { break; }
        }
      }
      long long occurrences = x / multiple;
      if (__builtin_popcount(mask) % 2 == 0) {
        result -= occurrences;
      } else {
        result += occurrences;
      }
    }
    return result;
  }

 public:
  long long findKthSmallest(vector<int>& coins, int k) {
    long long lo = 1;
    long long hi = coins[0];
    for (int coin : coins) { hi = min((long long)coin, hi); }
    hi *= k;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (count(mid, coins) >= k) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
