// 2305. Fair Distribution of Cookies
// https://leetcode.com/problems/fair-distribution-of-cookies/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  int go(vector<int>& cookies, int k, int curr, vector<int>& sums, int bestSoFar) {
    if (curr == (int)cookies.size()) {
      int ans = sums[0];
      for (int i = 1; i < k; ++i) ans = max(ans, sums[i]);
      return ans;
    }

    int ans = bestSoFar;
    for (int i = 0; i < k; ++i) {
      sums[i] += cookies[curr];
      if (sums[i] < ans) ans = min(ans, go(cookies, k, curr + 1, sums, ans));
      sums[i] -= cookies[curr];
    }

    return ans;
  }

 public:
  int distributeCookies(vector<int>& cookies, int k) {
    vector<int> sums = vector<int>(k, 0);
    return go(cookies, k, 0, sums, numeric_limits<int>::max());
  }
};
