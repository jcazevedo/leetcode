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
    int sum = nums[0];
    for (int i = 1; i < n; ++i) {
      maximum = max(maximum, nums[i]);
      sum += nums[i];
    }
    return maximum * n - sum;
  }
};
