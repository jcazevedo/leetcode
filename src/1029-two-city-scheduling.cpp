// 1029. Two City Scheduling
// https://leetcode.com/problems/two-city-scheduling/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int N = costs.size();
    int tot_sum = 0;
    vector<int> diffs;
    for (vector<int> cost : costs) {
      tot_sum += cost[0];
      diffs.push_back(cost[1] - cost[0]);
    }
    sort(diffs.begin(), diffs.end());
    for (int i = 0; i < N / 2; ++i) tot_sum += diffs[i];
    return tot_sum;
  }
};
