// 2425. Bitwise XOR of All Pairings
// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include <vector>

using namespace std;

class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size(), N2 = nums2.size(), ans = 0;
    if (N2 % 2) {
      for (int i = 0; i < N1; ++i) { ans ^= nums1[i]; }
    }
    if (N1 % 2) {
      for (int i = 0; i < N2; ++i) { ans ^= nums2[i]; }
    }
    return ans;
  }
};
