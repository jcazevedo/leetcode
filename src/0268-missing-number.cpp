// 268. Missing Number
// https://leetcode.com/problems/missing-number/

#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int totSum = nums.size() * (nums.size() + 1) / 2;
    int currSum = 0;
    for (int num : nums)
      currSum += num;
    return totSum - currSum;
  }
};
