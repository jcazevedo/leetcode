// 1752. Check if Array Is Sorted and Rotated
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <vector>

using namespace std;

class Solution {
 public:
  bool check(vector<int>& nums) {
    int n = nums.size();
    int wrong = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < nums[(i + n - 1) % n]) { ++wrong; }
    }
    return wrong <= 1;
  }
};
