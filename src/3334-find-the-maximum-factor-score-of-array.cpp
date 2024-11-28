// 3334. Find the Maximum Factor Score of Array
// https://leetcode.com/problems/find-the-maximum-factor-score-of-array/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
 private:
  long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }

  long long lcm(long long a, long long b) { return abs(a * b) / gcd(a, b); }

  long long maxFactorScore(vector<int>& nums, int rem) {
    int n = nums.size();
    long long l = -1L, g = -1L;
    for (int i = 0; i < n; ++i) {
      if (i == rem) { continue; }
      if (l == -1) {
        l = nums[i];
      } else {
        l = lcm(l, nums[i]);
      }
      if (g == -1) {
        g = nums[i];
      } else {
        g = gcd(g, nums[i]);
      }
    }
    if (l == -1 && g == -1) { return 0L; }
    return l * g;
  }

 public:
  long long maxScore(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0L;
    for (int rem = -1; rem < n; ++rem) { ans = max(ans, maxFactorScore(nums, rem)); }
    return ans;
  }
};
