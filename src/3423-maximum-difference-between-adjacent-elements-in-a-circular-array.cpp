// 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAdjacentDistance(vector<int>& nums) {
    int N = nums.size();
    int ans = 0;
    for (int i = 0; i < N - 1; ++i) { ans = max(ans, abs(nums[i + 1] - nums[i])); }
    ans = max(ans, abs(nums[N - 1] - nums[0]));
    return ans;
  }
};
