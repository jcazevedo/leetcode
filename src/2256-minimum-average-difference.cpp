// 2256. Minimum Average Difference
// https://leetcode.com/problems/minimum-average-difference/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    long long total = 0;
    for (int x : nums) { total += x; }
    long long best = numeric_limits<long long>::max();
    long long prefix = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      prefix += nums[i];
      long long suffix = total - prefix;
      long long diff = prefix / (i + 1);
      if (i + 1 < n) { diff -= suffix / (n - i - 1); }
      diff = abs(diff);
      if (diff < best) {
        best = diff;
        ans = i;
      }
    }
    return ans;
  }
};
