// 2444. Count Subarrays With Fixed Bounds
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int n = nums.size();
    int left = -1;
    int minIdx = -1;
    int maxIdx = -1;
    long long ans = 0L;
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= minK && nums[i] <= maxK) {
        if (nums[i] == minK) { minIdx = i; }
        if (nums[i] == maxK) { maxIdx = i; }
        if (minIdx != -1 && maxIdx != -1) { ans += min(minIdx, maxIdx) - left; }
      } else {
        left = i;
        minIdx = -1;
        maxIdx = -1;
      }
    }
    return ans;
  }
};
