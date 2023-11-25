// 2090. K Radius Subarray Averages
// https://leetcode.com/problems/k-radius-subarray-averages/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int N = nums.size();
    vector<long long> sums = vector<long long>(N, 0L);
    int len = 2 * k + 1;
    for (int i = 0; i < N; ++i) {
      if (i > 0) sums[i] = sums[i - 1];
      sums[i] += nums[i];
      if (i - len >= 0) sums[i] -= nums[i - len];
    }
    vector<int> ans = vector<int>(N, -1);
    for (int i = 0; i < N; ++i)
      if (i - k >= 0 && i + k < N) ans[i] = sums[i + k] / len;
    return ans;
  }
};
