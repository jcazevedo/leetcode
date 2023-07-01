// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < N; ++i) {
      int l = i + 1;
      int r = N - 1;
      while (l < r) {
        int s = nums[i] + nums[l] + nums[r];
        if (abs(best - target) > abs(s - target))
          best = s;
        if (s - target == 0) {
          while (l < r && nums[l] == nums[l + 1])
            ++l;
          while (l < r && nums[r] == nums[r - 1])
            --r;
          ++l;
          --r;
        } else if (s - target > 0) {
          --r;
        } else {
          ++l;
        }
      }
    }
    return best;
  }
};
