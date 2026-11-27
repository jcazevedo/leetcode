// 3946. Maximum Number of Items From Sale I
// https://leetcode.com/problems/maximum-number-of-items-from-sale-i/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumSaleItems(vector<vector<int>>& items, int budget) {
    int n = items.size();
    vector<int> dp(budget + 1, 0);
    for (int i = 0; i < n; ++i) {
      int extra = 1;
      int price = items[i][1];
      for (int j = 0; j < n; ++j) {
        if (i != j && items[j][0] % items[i][0] == 0) { ++extra; }
      }
      vector<int> bought(budget + 1, -1);
      for (int b = price; b <= budget; ++b) {
        bought[b] = dp[b - price] + extra;
        if (b >= 2 * price) { bought[b] = max(bought[b], bought[b - price] + 1); }
      }
      for (int b = price; b <= budget; ++b) { dp[b] = max(dp[b], bought[b]); }
    }
    return dp[budget];
  }
};
