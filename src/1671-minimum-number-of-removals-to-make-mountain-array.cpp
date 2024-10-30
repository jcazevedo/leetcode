// 1671. Minimum Number of Removals to Make Mountain Array
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int N = nums.size();
    int ans = N;
    for (int i = 1; i < N - 1; ++i) {
      int peak = nums[i];
      vector<int> left;
      int j;
      for (j = 0; j < i; ++j) {
        if (nums[j] >= peak) { continue; }
        left.push_back(nums[j]);
        break;
      }
      ++j;
      for (; j < i; ++j) {
        if (nums[j] >= peak) { continue; }
        if (nums[j] > left.back()) {
          left.push_back(nums[j]);
        } else {
          int low = lower_bound(begin(left), end(left), nums[j]) - begin(left);
          left[low] = nums[j];
        }
      }
      if (left.empty()) { continue; }
      vector<int> right;
      for (j = N - 1; j > i; --j) {
        if (nums[j] >= peak) { continue; }
        right.push_back(nums[j]);
        break;
      }
      --j;
      for (; j > i; --j) {
        if (nums[j] >= peak) { continue; }
        if (nums[j] > right.back()) {
          right.push_back(nums[j]);
        } else {
          int low = lower_bound(begin(right), end(right), nums[j]) - begin(right);
          right[low] = nums[j];
        }
      }
      if (right.empty()) { continue; }
      ans = min(ans, N - ((int)left.size() + (int)right.size() + 1));
    }
    return ans;
  }
};
