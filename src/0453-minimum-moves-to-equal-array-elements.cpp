// 453. Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = 0;
    int added = 0;
    for (int i = 1; i < n; ++i) {
      int diff = nums[i] - nums[i - 1];
      ans += (diff + added);
      added += diff;
    }
    return ans;
  }
};
