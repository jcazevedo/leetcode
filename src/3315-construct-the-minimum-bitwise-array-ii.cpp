// 3315. Construct the Minimum Bitwise Array II
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      if (nums[i] % 2 == 0) { continue; }
      int b = 1;
      while (nums[i] & (b << 1)) { b <<= 1; }
      ans[i] = nums[i] - b;
    }
    return ans;
  }
};
