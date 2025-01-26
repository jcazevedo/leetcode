// 3432. Count Partitions with Even Sum Difference
// https://leetcode.com/problems/count-partitions-with-even-sum-difference/

#include <vector>

using namespace std;

class Solution {
 public:
  int countPartitions(vector<int>& nums) {
    int N = nums.size();
    int r = 0;
    for (int i = 0; i < N; ++i) { r += nums[i]; }
    int ans = 0;
    int l = 0;
    for (int i = 0; i < N - 1; ++i) {
      l += nums[i];
      r -= nums[i];
      if ((l - r) % 2 == 0) { ++ans; }
    }
    return ans;
  }
};
