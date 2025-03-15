// 2560. House Robber IV
// https://leetcode.com/problems/house-robber-iv/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int r, const vector<int>& nums, int k) {
    int n = nums.size();
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] <= r) {
        ++tot;
        ++i;
      }
    }
    return tot >= k;
  }

 public:
  int minCapability(vector<int>& nums, int k) {
    int lo = 1, hi = 0;
    for (int n : nums) { hi = max(hi, n); }
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(mid, nums, k)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
