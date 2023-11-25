// 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int m = 0, l = 0, h = nums.size() - 1;

    while (l < h) {
      m = (l + h) / 2;
      if (nums[m] > nums[m + 1]) {
        h = m;
      } else if (nums[m] < nums[m + 1]) {
        l = m + 1;
      }
    }

    return l;
  }
};
