// 1359. Count All Valid Pickup and Delivery Options
// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  inline long long sum_to(int n) { return (long long)n * (n + 1) / 2; }

 public:
  int countOrders(int n) {
    vector<long long> dp(n + 1, 0L);
    dp[1] = 1L;

    for (int i = 2; i <= n; ++i) {
      int prev_len = (i - 1) * 2;
      dp[i] = (dp[i - 1] * sum_to(prev_len + 1)) % MOD;
    }

    return dp[n];
  }
};
