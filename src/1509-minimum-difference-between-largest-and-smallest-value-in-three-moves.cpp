// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDifference(vector<int>& nums) {
    int n = nums.size();
    if (n <= 4) { return 0; }
    sort(nums.begin(), nums.end());
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < 4; ++i) { ans = min(ans, nums[n - 4 + i] - nums[i]); }
    return ans;
  }
};
