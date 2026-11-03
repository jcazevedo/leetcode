// 3736. Minimum Moves to Equal Array Elements III
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int n = nums.size();
    int maximum = nums[0];
    for (int i = 1; i < n; ++i) { maximum = max(maximum, nums[i]); }
    int ans = 0;
    for (int i = 0; i < n; ++i) { ans += maximum - nums[i]; }
    return ans;
  }
};
