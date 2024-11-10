// 3097. Shortest Subarray With OR at Least K II
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  int minimumSubarrayLength(vector<int>& nums, int k) {
    int ans = -1, l = 0, r = 0, N = nums.size();
    vector<int> cnt(32, 0);
    while (r < N) {
      for (int b = 0; b < 32; ++b) {
        if (nums[r] & (1 << b)) { ++cnt[b]; }
      }
      while (l <= r) {
        int curr = 0;
        for (int b = 0; b < 32; ++b) {
          if (cnt[b]) { curr |= (1 << b); }
        }
        if (curr < k) { break; }
        int len = r - l + 1;
        if (ans == -1 || len < ans) { ans = len; }
        for (int b = 0; b < 32; ++b) {
          if (nums[l] & (1 << b)) { --cnt[b]; }
        }
        ++l;
      }
      ++r;
    }
    return ans;
  }
};
