// 1863. Sum of All Subset XOR Totals
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/

#include <vector>

using namespace std;

class Solution {
 public:
  int subsetXORSum(vector<int>& nums) {
    int ans = 0, n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
      int tot = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) { tot ^= nums[j]; }
      }
      ans += tot;
    }
    return ans;
  }
};
