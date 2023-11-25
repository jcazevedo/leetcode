// 1877. Minimize Maximum Pair Sum in Array
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < N / 2; ++i) ans = max(ans, nums[i] + nums[N - i - 1]);
    return ans;
  }
};
