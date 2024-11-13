// 2563. Count the Number of Fair Pairs
// https://leetcode.com/problems/count-the-number-of-fair-pairs/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(begin(nums), end(nums));
    int N = nums.size();
    long long ans = 0L;
    for (int i = 0; i < N; ++i) {
      ans += upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) -
             lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]);
    }
    return ans;
  }
};
