// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int n0 = 0, n1 = 0, n2 = 0, N = nums.size();
    for (int i = 0; i < N; i++) {
      if (nums[i] == 2) {
        n2++;
        nums[n0 + n1 + n2 - 1] = nums[i];
      } else if (nums[i] == 1) {
        n1++;
        nums[n0 + n1 - 1] = nums[i];
        if (n2 > 0)
          nums[n0 + n1 + n2 - 1] = 2;
      } else if (nums[i] == 0) {
        n0++;
        nums[n0 - 1] = nums[i];
        if (n1 > 0)
          nums[n0 + n1 - 1] = 1;
        if (n2 > 0)
          nums[n0 + n1 + n2 - 1] = 2;
      }
    }
  }
};
