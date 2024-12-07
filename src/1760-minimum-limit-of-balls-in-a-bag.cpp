// 1760. Minimum Limit of Balls in a Bag
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(int target, vector<int>& nums, int ops) {
    for (int num : nums) {
      if (num <= target) { continue; }
      int div = (num + target - 1) / target;
      if (div - 1 > ops) { return false; }
      ops -= div - 1;
    }
    return true;
  }

 public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    int lo = 1, hi = *max_element(nums.begin(), nums.end());
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(mid, nums, maxOperations)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
