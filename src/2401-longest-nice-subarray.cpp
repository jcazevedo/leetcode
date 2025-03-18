// 2401. Longest Nice Subarray
// https://leetcode.com/problems/longest-nice-subarray/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int used = 0, s = 0, best = 0, n = nums.size();
    for (int e = 0; e < n; ++e) {
      while ((used & nums[e]) != 0) {
        used ^= nums[s];
        ++s;
      }
      used |= nums[e];
      best = max(best, e - s + 1);
    }
    return best;
  }
};
