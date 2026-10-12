// 2897. Apply Operations on Array to Maximize Sum of Squares
// https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int maxSum(vector<int>& nums, int k) {
    vector<int> count(31, 0);
    for (int num : nums) {
      for (int bit = 0; bit < 31; ++bit) {
        if (num & (1 << bit)) { ++count[bit]; }
      }
    }
    long long ans = 0L;
    for (int i = 0; i < k; ++i) {
      long long value = 0L;
      for (int bit = 0; bit < 31; ++bit) {
        if (count[bit] > 0) {
          value |= 1 << bit;
          --count[bit];
        }
      }
      ans = (ans + value * value) % MOD;
    }
    return ans;
  }
};
