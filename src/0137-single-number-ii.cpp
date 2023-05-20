// 137. Single Number II
// https://leetcode.com/problems/single-number-ii/

#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int L = nums.size(), a = 0, b = 0;
    for (int i = 0; i < L; i++) {
      int ta = (a & ~b & ~nums[i]) | (~a & b & nums[i]);
      b = (~a & b & ~nums[i]) | (~a & ~b & nums[i]);
      a = ta;
    }
    return b;
  }
};
