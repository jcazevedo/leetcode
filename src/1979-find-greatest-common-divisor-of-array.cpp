// 1979. Find Greatest Common Divisor of Array
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 private:
  int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

 public:
  int findGCD(vector<int>& nums) {
    int lo = numeric_limits<int>::max(), hi = numeric_limits<int>::min();
    for (int num : nums) {
      lo = min(lo, num);
      hi = max(hi, num);
    }
    return gcd(lo, hi);
  }
};
