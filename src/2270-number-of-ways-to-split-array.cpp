// 2270. Number of Ways to Split Array
// https://leetcode.com/problems/number-of-ways-to-split-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    long long r = 0L, l = 0L;
    for (int i = 0; i < N; ++i) { r += nums[i]; }
    for (int i = 0; i < N - 1; ++i) {
      r -= nums[i];
      l += nums[i];
      if (l >= r) { ++ans; }
    }
    return ans;
  }
};
