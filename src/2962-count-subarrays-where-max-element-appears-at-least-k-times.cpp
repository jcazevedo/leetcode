// 2962. Count Subarrays Where Max Element Appears at Least K Times
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int maxV = nums[0];
    for (int i = 1; i < n; ++i) { maxV = max(maxV, nums[i]); }
    priority_queue<int, vector<int>, greater<int>> minPQ;
    long long ans = 0L;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == maxV) { minPQ.push(i); }
      while ((int)minPQ.size() > k) { minPQ.pop(); }
      if ((int)minPQ.size() == k) { ans += minPQ.top() + 1; }
    }
    return ans;
  }
};
