#include <vector>

using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int N = nums.size();
    int m, l = 0, r = N - 1;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) return true;
      if (nums[m] < nums[r]) {
        if (nums[m] < target && target <= nums[r])
          l = m + 1;
        else
          r = m - 1;
      } else if (nums[m] > nums[r]) {
        if (nums[m] > target && target >= nums[l])
          r = m - 1;
        else
          l = m + 1;
      } else {
        r--;
      }
    }
    return false;
  }
};
