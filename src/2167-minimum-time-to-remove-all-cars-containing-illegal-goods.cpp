// 2167. Minimum Time to Remove All Cars Containing Illegal Goods
// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumTime(string s) {
    int n = s.size();
    vector<int> dpL(n, 0);
    for (int i = 0; i < n; ++i) {
      int prev = i > 0 ? dpL[i - 1] : 0;
      if (s[i] == '0') {
        dpL[i] = prev;
      } else {
        dpL[i] = min(i + 1, prev + 2);
      }
    }
    vector<int> dpR(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      int prev = i < n - 1 ? dpR[i + 1] : 0;
      if (s[i] == '0') {
        dpR[i] = prev;
      } else {
        dpR[i] = min(n - i, prev + 2);
      }
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i <= n; ++i) {
      if (i == 0) {
        ans = min(ans, dpR[i]);
      } else if (i == n) {
        ans = min(ans, dpL[i - 1]);
      } else {
        ans = min(ans, dpL[i - 1] + dpR[i]);
      }
    }
    return ans;
  }
};
