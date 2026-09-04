// 3903. Smallest Stable Index I
// https://leetcode.com/problems/smallest-stable-index-i/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> maxV(n, -1), minV(n, -1);
    maxV[0] = nums[0];
    for (int i = 1; i < n; ++i) { maxV[i] = max(maxV[i - 1], nums[i]); }
    minV[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) { minV[i] = min(minV[i + 1], nums[i]); }
    for (int i = 0; i < n; ++i) {
      int score = maxV[i] - minV[i];
      if (score > k) { continue; }
      return i;
    }
    return -1;
  }
};
