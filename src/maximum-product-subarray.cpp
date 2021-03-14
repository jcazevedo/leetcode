#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int best_neg = -1;
    int best_pos = -1;
    int ans = nums[0];
    if (nums[0] < 0)
      best_neg = -nums[0];
    else if (nums[0] > 0)
      best_pos = nums[0];
    else {
      best_neg = -1;
      best_pos = -1;
    }
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
      if (nums[i] < 0) {
        int prev_best_pos = best_pos;
        int prev_best_neg = best_neg;
        if (prev_best_neg != -1)
          best_pos = prev_best_neg * abs(nums[i]);
        else
          best_pos = -1;
        if (prev_best_pos != -1)
          best_neg = prev_best_pos * abs(nums[i]);
        else
          best_neg = abs(nums[i]);
      }
      if (nums[i] == 0) {
        best_neg = -1;
        best_pos = -1;
        ans = max(ans, 0);
      }
      if (nums[i] > 0) {
        if (best_pos != -1)
          best_pos = best_pos * nums[i];
        else
          best_pos = nums[i];
        if (best_neg != -1)
          best_neg = best_neg * nums[i];
      }
      ans = max(ans, best_pos);
    }
    return ans;
  }
};
