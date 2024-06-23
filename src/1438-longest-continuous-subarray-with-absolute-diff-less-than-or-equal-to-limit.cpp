// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
// Limit
// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    priority_queue<pair<int, int>> maxPQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minPQ;
    int left = 0;
    int best = 0;
    int n = nums.size();
    for (int right = 0; right < n; ++right) {
      maxPQ.push({nums[right], right});
      minPQ.push({nums[right], right});
      while (maxPQ.top().first - minPQ.top().first > limit) {
        left = min(maxPQ.top().second, minPQ.top().second) + 1;
        while (maxPQ.top().second < left) { maxPQ.pop(); }
        while (minPQ.top().second < left) { minPQ.pop(); }
      }
      best = max(best, right - left + 1);
    }
    return best;
  }
};
