#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int N = nums.size();
    int m, l = 0, r = N - 1;
    while (r >= 0 && nums[r] == nums[l])
      r--;
    while (l < r) {
      m = (l + r) / 2;
      if (nums[m] <= nums[r] && nums[m] >= nums[l])
        break;
      if (nums[m] >= nums[l]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return nums[l];
  }
};
