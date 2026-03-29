// 3392. Count Subarrays of Length Three With a Condition
// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/

#include <vector>

using namespace std;

class Solution {
 public:
  int countSubarrays(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
      if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) { ++ans; }
    }
    return ans;
  }
};
