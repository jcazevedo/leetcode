// 862. Shortest Subarray with Sum at Least K
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/

#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int shortestSubarray(vector<int>& nums, int k) {
    int N = nums.size();
    int ans = numeric_limits<int>::max();
    long long curr = 0L;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < N; ++i) {
      curr += nums[i];
      if (curr >= k) { ans = min(ans, i + 1); }
      while (!pq.empty() && curr - pq.top().first >= k) {
        ans = min(ans, i - pq.top().second);
        pq.pop();
      }
      pq.emplace(curr, i);
    }
    return ans == numeric_limits<int>::max() ? -1 : ans;
  }
};
