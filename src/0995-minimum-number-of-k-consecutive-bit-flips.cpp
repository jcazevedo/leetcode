// 995. Minimum Number of K Consecutive Bit Flips
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

#include <vector>

using namespace std;

class Solution {
 public:
  int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
    vector<bool> flipped(n, false);
    int prevFlips = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i >= k) {
        if (flipped[i - k]) { --prevFlips; }
      }
      if (prevFlips % 2 == nums[i]) {
        if (i + k > n) { return -1; }
        ++prevFlips;
        flipped[i] = true;
        ++ans;
      }
    }
    return ans;
  }
};
