// 1567. Maximum Length of Subarray With Positive Product
// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

#include <vector>

using namespace std;

class Solution {
public:
  int getMaxLen(vector<int>& nums) {
    int ans = 0;

    vector<int> longest_pos(nums.size(), 0);
    vector<int> longest_neg(nums.size(), 0);

    if (nums[0] > 0)
      longest_pos[0] = 1;
    else if (nums[0] < 0)
      longest_neg[0] = 1;

    if (nums[0] > 0)
      ans = 1;

    for (int i = 1; i < (int)nums.size(); ++i) {
      if (nums[i] > 0) {
        longest_pos[i] = longest_pos[i - 1] + 1;
        longest_neg[i] = longest_neg[i - 1] > 0 ? longest_neg[i - 1] + 1 : 0;
      } else if (nums[i] < 0) {
        longest_pos[i] = longest_neg[i - 1] > 0 ? longest_neg[i - 1] + 1 : 0;
        longest_neg[i] = longest_pos[i - 1] > 0 ? longest_pos[i - 1] + 1 : 1;
      } else
        longest_pos[i] = longest_neg[i] = 0;
      ans = max(ans, longest_pos[i]);
    }

    return ans;
  }
};
