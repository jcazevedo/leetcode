#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int top = cost.size();

    vector<int> dp = vector<int>(top + 1, numeric_limits<int>::max());
    dp[0] = dp[1] = 0;

    for (int i = 0; i < top; ++i) {
      if (i + 1 <= top)
        dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
      if (i + 2 <= top)
        dp[i + 2] = min(dp[i + 2], dp[i] + cost[i]);
    }

    return dp[top];
  }
};
