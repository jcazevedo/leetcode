// 3903. Smallest Stable Index I
// https://leetcode.com/problems/smallest-stable-index-i/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> minV(n);
    minV[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) { minV[i] = min(minV[i + 1], nums[i]); }
    int maxV = -1;
    for (int i = 0; i < n; ++i) {
      maxV = max(maxV, nums[i]);
      int score = maxV - minV[i];
      if (score > k) { continue; }
      return i;
    }
    return -1;
  }
};
