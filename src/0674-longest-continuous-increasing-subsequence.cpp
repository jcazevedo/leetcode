// 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int N = nums.size(), ans = 1, curr = 1;
    for (int i = 1; i < N; ++i) {
      if (nums[i] > nums[i - 1])
        ++curr;
      else
        curr = 1;
      ans = max(ans, curr);
    }
    return ans;
  }
};
