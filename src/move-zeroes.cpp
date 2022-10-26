#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int N = nums.size(), zeroIdx = 0;
    for (int i = 0; i < N; ++i)
      if (nums[i] != 0) swap(nums[zeroIdx++], nums[i]);
  }
};
