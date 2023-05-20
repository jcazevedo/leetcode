// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int L = nums.size();
    if (L == 0)
      return 0;
    int j = 1;
    for (int i = 1; i < L; i++)
      if (nums[i] != nums[i - 1])
        nums[j++] = nums[i];
    return j;
  }
};
