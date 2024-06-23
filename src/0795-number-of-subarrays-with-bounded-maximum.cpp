// 795. Number of Subarrays with Bounded Maximum
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

#include <vector>

using namespace std;

class Solution {
 private:
  int numSubarraysAllLower(const vector<int>& nums, int limit) {
    int ans = 0;
    int curr = 0;
    for (int num : nums) {
      if (num <= limit) {
        curr += 1;
      } else {
        curr = 0;
      }
      ans += curr;
    }
    return ans;
  }

 public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    return numSubarraysAllLower(nums, right) - numSubarraysAllLower(nums, left - 1);
  }
};
