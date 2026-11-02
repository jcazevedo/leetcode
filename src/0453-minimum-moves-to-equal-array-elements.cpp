// 453. Minimum Moves to Equal Array Elements
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int n = nums.size();
    int minimum = nums[0];
    for (int i = 1; i < n; ++i) { minimum = min(nums[i], minimum); }
    int ans = 0;
    for (int i = 0; i < n; ++i) { ans += nums[i] - minimum; }
    return ans;
  }
};
