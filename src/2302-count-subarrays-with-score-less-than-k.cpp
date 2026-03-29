// 2302. Count Subarrays With Score Less Than K
// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

#include <vector>

using namespace std;

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    int n = nums.size();
    long long ans = 0, sum = 0, l = 0;
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      while (sum * (r - l + 1) >= k) { sum -= nums[l++]; }
      ans += r - l + 1;
    }
    return ans;
  }
};
