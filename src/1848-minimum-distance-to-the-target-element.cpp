// 1848. Minimum Distance to the Target Element
// https://leetcode.com/problems/minimum-distance-to-the-target-element/

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMinDistance(vector<int>& nums, int target, int start) {
    int n = nums.size(), ans = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != target) { continue; }
      ans = min(ans, abs(i - start));
    }
    return ans;
  }
};
