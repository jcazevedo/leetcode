#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int lb = -1, ub = -1, m, l = 0, r = nums.size() - 1;
    while (l <= r) {
      m = (l + r) / 2;
      if (nums[m] == target) {
        lb = m;
        r = m - 1;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    l = 0;
    r = nums.size() - 1;
    while (l <= r) {
      m = (l + r) / 2;
      if (nums[m] == target) {
        ub = m;
        l = m + 1;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    vector<int> res;
    res.push_back(lb);
    res.push_back(ub);
    return res;
  }
};
