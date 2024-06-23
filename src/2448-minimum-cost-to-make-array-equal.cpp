// 2448. Minimum Cost to Make Array Equal
// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int N = nums.size();
    vector<pair<int, long long>> ncs;
    for (int i = 0; i < N; ++i) ncs.push_back(make_pair(nums[i], cost[i]));
    sort(ncs.begin(), ncs.end());
    vector<long long> costs = vector<long long>(N, 0L);
    costs[0] = ncs[0].second;
    for (int i = 1; i < N; ++i) costs[i] = ncs[i].second + costs[i - 1];
    long long curr = 0L;
    for (int i = 1; i < N; ++i) curr += ncs[i].second * (ncs[i].first - ncs[0].first);
    long long ans = curr;
    for (int i = 1; i < N; ++i) {
      int diff = ncs[i].first - ncs[i - 1].first;
      curr += costs[i - 1] * diff;
      curr -= (costs[N - 1] - costs[i - 1]) * diff;
      ans = min(ans, curr);
    }
    return ans;
  }
};
