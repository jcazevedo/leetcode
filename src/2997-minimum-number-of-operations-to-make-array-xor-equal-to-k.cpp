// 2997. Minimum Number of Operations to Make Array XOR Equal to K
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int ans = 0;
    for (int d = 0; d < 20; ++d) {
      int res = 0;
      for (int num : nums) res ^= (num & (1 << d));
      if (res != (k & (1 << d))) ++ans;
    }
    return ans;
  }
};
