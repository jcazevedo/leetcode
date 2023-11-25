// 217. Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int L = nums.size();
    for (int i = 0; i < L - 1; i++)
      if (nums[i] == nums[i + 1]) return true;
    return false;
  }
};
