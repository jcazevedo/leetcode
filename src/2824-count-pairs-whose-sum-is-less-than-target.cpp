// 2824. Count Pairs Whose Sum is Less than Target
// https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    int N = nums.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += lower_bound(begin(nums) + i + 1, end(nums), target - nums[i]) - (begin(nums) + i + 1);
    }
    return ans;
  }
};
