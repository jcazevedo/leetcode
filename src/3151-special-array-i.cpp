// 3151. Special Array I
// https://leetcode.com/problems/special-array-i/

#include <vector>

using namespace std;

class Solution {
 public:
  bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] % 2 == nums[i - 1] % 2) { return false; }
    }
    return true;
  }
};
