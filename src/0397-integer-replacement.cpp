// 397. Integer Replacement
// https://leetcode.com/problems/integer-replacement/

#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<long long, int> dp;

  int go(long long n) {
    if (dp.count(n) > 0)
      return dp[n];
    if (n == 1)
      return 0;
    if (n % 2 == 0)
      return dp[n] = go(n / 2) + 1;
    return dp[n] = min(go(n + 1), go(n - 1)) + 1;
  }

public:
  int integerReplacement(int n) {
    dp.clear();
    return go(n);
  }
};
