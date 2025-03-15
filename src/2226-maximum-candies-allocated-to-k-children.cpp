// 2226. Maximum Candies Allocated to K Children
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int c, const vector<int>& candies, long long k) {
    long long tot = 0L;
    for (int candy : candies) { tot += candy / c; }
    return tot >= k;
  }

 public:
  int maximumCandies(vector<int>& candies, long long k) {
    int lo = 0, hi = 0;
    for (int c : candies) { hi = max(hi, c); }
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (good(mid, candies, k)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return lo;
  }
};
