// 3411. Maximum Subarray With Equal Products
// https://leetcode.com/problems/maximum-subarray-with-equal-products/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  int gcd(int a, int b) {
    while (b != 0) {
      int rem = a % b;
      a = b;
      b = rem;
    }
    return a;
  }

  int lcm(int a, int b) {
    if (a == 0 || b == 0) { return 0; }
    return (a / gcd(a, b)) * b;
  }

 public:
  int maxLength(vector<int>& nums) {
    int n = nums.size();
    int ans = 2;
    for (int i = 0; i < n; ++i) {
      int l = 1;
      for (int j = i; j < n; ++j) {
        if (gcd(l, nums[j]) != 1) { break; }
        l = lcm(l, nums[j]);
        ans = max(ans, j - i + 1);
      }
    }
    return ans;
  }
};
