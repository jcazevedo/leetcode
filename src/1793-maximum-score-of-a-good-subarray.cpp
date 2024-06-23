// 1793. Maximum Score of a Good Subarray
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/

#include <vector>

using namespace std;

class Solution {
 public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int left = k;
    int right = k;
    int ans = nums[k];
    int minV = nums[k];
    while (left > 0 || right < n - 1) {
      int nextLeft = left > 0 ? nums[left - 1] : 0;
      int nextRight = right < n - 1 ? nums[right + 1] : 0;
      if (nextLeft < nextRight) {
        ++right;
        minV = min(minV, nums[right]);
      } else {
        --left;
        minV = min(minV, nums[left]);
      }
      ans = max(ans, minV * (right - left + 1));
    }
    return ans;
  }
};
