// 3427. Sum of Variable Length Subarrays
// https://leetcode.com/problems/sum-of-variable-length-subarrays/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums) {
    int N = nums.size();
    vector<int> prefixSum(N, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < N; ++i) { prefixSum[i] = prefixSum[i - 1] + nums[i]; }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      int sum = prefixSum[i];
      int start = max(0, i - nums[i]);
      if (start > 0) { sum -= prefixSum[start - 1]; }
      ans += sum;
    }
    return ans;
  }
};
