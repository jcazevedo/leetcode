// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    vector<bool> flipped(n, false);
    int prevFlips = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i >= 3 && flipped[i - 3]) { --prevFlips; }
      if (prevFlips % 2 == nums[i]) {
        if (i + 3 > n) { return -1; }
        ++prevFlips;
        flipped[i] = true;
        ++ans;
      }
    }
    return ans;
  }
};
