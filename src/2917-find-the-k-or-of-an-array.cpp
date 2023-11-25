// 2917. Find the K-or of an Array
// https://leetcode.com/problems/find-the-k-or-of-an-array/

#include <vector>

using namespace std;

class Solution {
 public:
  int findKOr(vector<int>& nums, int k) {
    vector<int> cnt(31, 0);
    for (int i = 0; i < 31; ++i)
      for (int num : nums)
        if ((1 << i) & num) cnt[i]++;
    int ans = 0;
    for (int i = 0; i < 31; ++i)
      if (cnt[i] >= k) ans |= (1 << i);
    return ans;
  }
};
