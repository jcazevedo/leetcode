// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int N = nums.size(), i = N - 2, j = N - 1;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i < 0)
      reverse(nums.begin(), nums.end());
    else {
      while (j > i && nums[j] <= nums[i]) --j;
      swap(nums[i], nums[j]);
      reverse(begin(nums) + i + 1, end(nums));
    }
  }
};
