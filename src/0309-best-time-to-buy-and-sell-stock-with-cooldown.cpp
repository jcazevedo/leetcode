// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    int end_with_sell = 0;
    int end_with_buy = INT_MIN;
    int prev_buy = 0, prev_sell = 0;
    for (int i = 0; i < N; ++i) {
      prev_buy = end_with_buy;
      end_with_buy = max(end_with_buy, prev_sell - prices[i]);
      prev_sell = end_with_sell;
      end_with_sell = max(end_with_sell, prev_buy + prices[i]);
    }
    return end_with_sell;
  }
};
