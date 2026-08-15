// 3702. Longest Subsequence With Non-Zero Bitwise XOR
// https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/

#include <vector>

using namespace std;

class Solution {
 public:
  int longestSubsequence(vector<int>& nums) {
    int tot = 0;
    bool hasNonZero = false;
    for (int num : nums) {
      tot ^= num;
      if (num != 0) { hasNonZero = true; }
    }
    if (tot != 0) { return nums.size(); }
    if (hasNonZero) { return nums.size() - 1; }
    return 0;
  }
};
