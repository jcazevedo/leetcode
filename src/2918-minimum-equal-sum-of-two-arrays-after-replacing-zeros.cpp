// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long s1 = 0, s2 = 0, z1 = 0, z2 = 0;
    for (int x : nums1) {
      s1 += x;
      if (x == 0) { ++z1; }
    }
    for (int x : nums2) {
      s2 += x;
      if (x == 0) { ++z2; }
    }
    long long m1 = s1 + z1, m2 = s2 + z2;
    if (m1 < m2 && z1 == 0) { return -1; }
    if (m2 < m1 && z2 == 0) { return -1; }
    return max(m1, m2);
  }
};
