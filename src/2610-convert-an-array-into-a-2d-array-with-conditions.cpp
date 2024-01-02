// 2610. Convert an Array Into a 2D Array With Conditions
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findMatrix(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int N = nums.size(), idx = 0;
    for (int i = 0; i < N; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        ++idx;
      else
        idx = 0;

      if (idx >= (int)ans.size()) ans.push_back(vector<int>());

      ans[idx].push_back(nums[i]);
    }

    return ans;
  }
};
