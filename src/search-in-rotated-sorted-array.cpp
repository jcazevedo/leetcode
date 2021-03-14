#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int N = nums.size();
    int m, l = 0, r = N - 1;
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
    int o = l;
    l = 0;
    r = N - 1;
    while (l <= r) {
      m = (l + r) / 2;
      int c = nums[(o + m) % N];
      if (c < target) {
        l = m + 1;
      } else if (c > target) {
        r = m - 1;
      } else {
        return (o + m) % N;
      }
    }
    return -1;
  }
};
