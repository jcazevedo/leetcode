// 1685. Sum of Absolute Differences in a Sorted Array
// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int N = nums.size();
    vector<int> prefixSum = vector<int>(N, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < N; ++i) prefixSum[i] = prefixSum[i - 1] + nums[i];
    vector<int> ans = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
      ans[i] = (prefixSum[N - 1] - prefixSum[i]) - nums[i] * (N - i - 1);
      if (i > 0) ans[i] += i * nums[i] - prefixSum[i - 1];
    }
    return ans;
  }
};
