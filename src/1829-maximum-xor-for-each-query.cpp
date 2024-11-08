// 1829. Maximum XOR for Each Query
// https://leetcode.com/problems/maximum-xor-for-each-query/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int tot = 0, N = nums.size();
    for (int i = 0; i < N; ++i) { tot ^= nums[i]; }
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      int b = 0, v = 0, curr = tot;
      while (b < maximumBit) {
        if (curr % 2 == 0) { v |= (1 << b); }
        curr /= 2;
        ++b;
      }
      ans[i] = v;
      tot ^= nums[N - i - 1];
    }
    return ans;
  }
};
