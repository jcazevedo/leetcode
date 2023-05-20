// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int best_from(int i, bool sell, vector<int>& prices, vector<vector<int>>& cache, int fee) {
    if (i >= (int)prices.size())
      return 0;

    if (cache[i][sell] == -1) {
      cache[i][sell] = best_from(i + 1, sell, prices, cache, fee);
      if (sell)
        cache[i][sell] = max(cache[i][sell], prices[i] - fee + best_from(i + 1, false, prices, cache, fee));
      else
        cache[i][sell] = max(cache[i][sell], -prices[i] + best_from(i + 1, true, prices, cache, fee));
    }

    return cache[i][sell];
  }

public:
  int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> cache = vector<vector<int>>(prices.size(), vector<int>(2, -1));
    return best_from(0, false, prices, cache, fee);
  }
};
