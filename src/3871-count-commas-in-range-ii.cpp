// 3871. Count Commas in Range II
// https://leetcode.com/problems/count-commas-in-range-ii/

class Solution {
 public:
  long long countCommas(long long n) {
    long long ans = 0L;
    for (long long t = 1000L; t <= n; t *= 1000L) { ans += n - t + 1; }
    return ans;
  }
};
