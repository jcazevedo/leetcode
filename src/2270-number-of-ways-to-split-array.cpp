// 2270. Number of Ways to Split Array
// https://leetcode.com/problems/number-of-ways-to-split-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int waysToSplitArray(vector<int>& nums) {
    int N = nums.size(), ans = 0;
    vector<long long> p(N);
    for (int i = 0; i < N; ++i) {
      if (i > 0) { p[i] = p[i - 1]; }
      p[i] += nums[i];
    }
    for (int i = 0; i < N - 1; ++i) {
      if (p[i] >= (p[N - 1] - p[i])) { ++ans; }
    }
    return ans;
  }
};
