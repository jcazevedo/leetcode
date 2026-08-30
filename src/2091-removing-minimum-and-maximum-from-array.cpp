// 2091. Removing Minimum and Maximum From Array
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeletions(vector<int>& nums) {
    int n = nums.size(), minValue = nums[0], minI = 0, maxValue = nums[0], maxI = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] > maxValue) {
        maxValue = nums[i];
        maxI = i;
      }
      if (nums[i] < minValue) {
        minValue = nums[i];
        minI = i;
      }
    }
    int ans = max(maxI + 1, minI + 1);
    ans = min(ans, max(n - maxI, n - minI));
    ans = min(ans, maxI + 1 + n - minI);
    ans = min(ans, minI + 1 + n - maxI);
    return ans;
  }
};
