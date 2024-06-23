// 857. Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int N = quality.size();
    vector<pair<double, int>> ratios;
    for (int i = 0; i < N; ++i) ratios.push_back({((double)wage[i]) / quality[i], quality[i]});
    sort(ratios.begin(), ratios.end());
    priority_queue<int> pq;
    long long tot = 0L;
    double ans = numeric_limits<double>::max();
    for (int i = 0; i < N; ++i) {
      pq.push(ratios[i].second);
      tot += ratios[i].second;
      if ((int)pq.size() > k) {
        tot -= pq.top();
        pq.pop();
      }
      if ((int)pq.size() == k) ans = min(ans, tot * ratios[i].first);
    }
    return ans;
  }
};
