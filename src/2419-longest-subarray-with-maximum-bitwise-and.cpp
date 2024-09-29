// 2419. Longest Subarray With Maximum Bitwise AND
// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int ans = 1, len = 1, best = nums[0], N = nums.size();
    for (int i = 1; i < N; ++i) {
      if (nums[i] == nums[i - 1]) {
        ++len;
      } else {
        len = 1;
      }
      if (nums[i] > best) {
        best = nums[i];
        ans = len;
      } else if (nums[i] == best) {
        ans = max(ans, len);
      }
    }
    return ans;
  }
};
