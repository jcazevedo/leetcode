#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int N = prices.size();
    if (k == 0 || N < 2)
      return 0;
    if (k >= N / 2) {
      int ans = 0;
      for (int i = 1; i < N; ++i) {
        int diff = prices[i] - prices[i - 1];
        if (diff > 0)
          ans += diff;
      }
      return ans;
    }
    vector<pair<int, int>> dp = vector<pair<int, int>>(k + 1, make_pair(0, 0));
    int price = -prices[0];
    for (int i = 0; i <= k; ++i)
      dp[i].first = price;
    for (int i = 0; i < N; ++i) {
      price = prices[i];
      for (int j = 1; j <= k; ++j) {
        dp[j].first = max(dp[j].first, dp[j - 1].second - price);
        dp[j].second = max(dp[j].second, dp[j].first + price);
      }
    }
    return dp[k].second;
  }
};
