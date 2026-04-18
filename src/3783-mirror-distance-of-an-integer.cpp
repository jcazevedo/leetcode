// 3783. Mirror Distance of an Integer
// https://leetcode.com/problems/mirror-distance-of-an-integer/

#include <cmath>

using namespace std;

class Solution {
 private:
  int reverse(int num) {
    int ans = 0;
    while (num) {
      ans = ans * 10 + num % 10;
      num /= 10;
    }
    return ans;
  }

 public:
  int mirrorDistance(int n) { return abs(n - reverse(n)); }
};
