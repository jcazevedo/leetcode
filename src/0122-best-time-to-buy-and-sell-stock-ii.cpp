// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int L = prices.size(), tot = 0;
    for (int i = 1; i < L; i++)
      if (prices[i] > prices[i - 1]) tot += (prices[i] - prices[i - 1]);
    return tot;
  }
};
