// 2779. Maximum Beauty of an Array After Applying Operation
// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumBeauty(vector<int>& nums, int k) {
    int N = nums.size(), ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N; ++i) {
      int target = nums[i] + 2 * k, lo = 0, hi = N - 1;
      while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (nums[mid] > target) {
          hi = mid - 1;
        } else {
          lo = mid;
        }
      }
      ans = max(ans, lo - i + 1);
    }
    return ans;
  }
};
