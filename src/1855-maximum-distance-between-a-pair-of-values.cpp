// 1855. Maximum Distance Between a Pair of Values
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size(), i = 0, ans = 0;
    for (int j = 0; j < n2; ++j) {
      while (i < n1 && nums2[j] < nums1[i]) { ++i; }
      if (i >= n1) { break; }
      if (nums2[j] >= nums1[i]) { ans = max(ans, j - i); }
    }
    return ans;
  }
};
