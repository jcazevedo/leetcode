// 462. Minimum Moves to Equal Array Elements II
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int target = nums[n / 2];
    int ans = 0;
    for (int n : nums) { ans += abs(n - target); }
    return ans;
  }
};
