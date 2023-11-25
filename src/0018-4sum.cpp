// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < N; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = N - 1; j >= 0; --j) {
        if (j + 1 < N && nums[j] == nums[j + 1]) continue;
        int l = i + 1;
        int r = j - 1;
        while (l < r) {
          long long s = (long long)nums[i] + nums[l] + nums[r] + nums[j];
          if (s == target) {
            res.push_back({nums[i], nums[l], nums[r], nums[j]});
            while (l < r && nums[l] == nums[l + 1]) ++l;
            while (l < r && nums[r] == nums[r - 1]) --r;
            ++l;
            --r;
          } else if (s > target) {
            --r;
          } else {
            ++l;
          }
        }
      }
    }
    return res;
  }
};
