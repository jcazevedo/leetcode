// 1493. Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int ans = 0, withZero = 0, withOne = 0;
    for (int num : nums) {
      if (num == 1) {
        ++withZero;
        ++withOne;
      } else {
        withZero = withOne + 1;
        withOne = 0;
      }
      ans = max(ans, max(max(withZero - 1, 0), max(withOne - 1, 0)));
    }
    return ans;
  }
};
