// 3789. Minimum Cost to Acquire Required Items
// https://leetcode.com/problems/minimum-cost-to-acquire-required-items/

#include <algorithm>

using namespace std;

class Solution {
 public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    int shared = min(need1, need2);
    return 1LL * shared * min(costBoth, cost1 + cost2) + 1LL * (need1 - shared) * min(cost1, costBoth) +
           1LL * (need2 - shared) * min(cost2, costBoth);
  }
};
