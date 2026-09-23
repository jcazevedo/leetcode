// 1658. Minimum Operations to Reduce X to Zero
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; ++i) { total += nums[i]; }
    int target = total - x;
    if (target < 0) { return -1; }
    if (target == 0) { return n; }
    int left = 0;
    int longest = -1;
    int window = 0;
    for (int right = 0; right < n; ++right) {
      window += nums[right];
      while (window > target) { window -= nums[left++]; }
      if (window == target) { longest = max(longest, right - left + 1); }
    }
    return longest == -1 ? -1 : n - longest;
  }
};
