// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; ++i) pow2[i] = (pow2[i - 1] * 2) % MOD;
    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
      if (nums[l] + nums[r] <= target) {
        ans = (ans + pow2[r - l]) % MOD;
        ++l;
      } else {
        --r;
      }
    }
    return ans;
  }
};
