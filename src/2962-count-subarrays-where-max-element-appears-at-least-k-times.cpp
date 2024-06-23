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
    queue<int> q;
    long long ans = 0L;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == maxV) { q.push(i); }
      while ((int)q.size() > k) { q.pop(); }
      if ((int)q.size() == k) { ans += q.front() + 1; }
    }
    return ans;
  }
};
