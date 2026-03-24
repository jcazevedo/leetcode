// 2256. Minimum Average Difference
// https://leetcode.com/problems/minimum-average-difference/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    vector<long long> pre(n), suf(n);
    pre[0] = nums[0];
    for (int i = 1; i < n; ++i) { pre[i] = pre[i - 1] + nums[i]; }
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) { suf[i] = suf[i + 1] + nums[i]; }
    long long best = numeric_limits<int>::max();
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      long long diff = pre[i] / (i + 1);
      if (i + 1 < n) { diff -= suf[i + 1] / (n - i - 1); }
      diff = abs(diff);
      if (diff < best) {
        best = diff;
        ans = i;
      }
    }
    return ans;
  }
};
