// 826. Most Profit Assigning Work
// https://leetcode.com/problems/most-profit-assigning-work/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty,
                          vector<int>& profit,
                          vector<int>& worker) {
    int ans = 0;
    sort(worker.begin(), worker.end());
    int N = difficulty.size();
    vector<vector<int>> dp;
    for (int i = 0; i < N; ++i) dp.push_back({difficulty[i], profit[i]});
    sort(dp.begin(), dp.end());
    int j = -1;
    int W = worker.size();
    priority_queue<int> profits;
    for (int i = 0; i < W; ++i) {
      while (j + 1 < N && dp[j + 1][0] <= worker[i]) {
        ++j;
        profits.push(dp[j][1]);
      }
      if (!profits.empty()) ans += profits.top();
    }
    return ans;
  }
};
