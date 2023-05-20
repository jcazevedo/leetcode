// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    vector<int> dp_left(N, 0);
    int min_so_far = prices[0];
    for (int i = 1; i < N; ++i) {
      dp_left[i] = max(dp_left[i - 1], prices[i] - min_so_far);
      min_so_far = min(min_so_far, prices[i]);
    }
    vector<int> dp_right(N, 0);
    int max_so_far = prices[N - 1];
    for (int i = N - 2; i >= 0; --i) {
      dp_right[i] = max(dp_right[i + 1], max_so_far - prices[i]);
      max_so_far = max(max_so_far, prices[i]);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int left = dp_left[i];
      int right = i + 1 < N ? dp_right[i + 1] : 0;
      ans = max(ans, left + right);
    }
    return ans;
  }
};
