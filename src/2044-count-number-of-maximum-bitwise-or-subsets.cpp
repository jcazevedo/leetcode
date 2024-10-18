// 2044. Count Number of Maximum Bitwise-OR Subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/

#include <vector>

using namespace std;

class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int N = nums.size(), maxOr = 0;
    for (int i = 0; i < N; ++i) { maxOr = maxOr | nums[i]; }
    int ans = 0;
    for (int i = 0; i < 1 << N; ++i) {
      int currOr = 0;
      for (int j = 0; j < N; ++j) {
        if (i & (1 << j)) { currOr = currOr | nums[j]; }
      }
      if (currOr == maxOr) { ++ans; }
    }
    return ans;
  }
};
