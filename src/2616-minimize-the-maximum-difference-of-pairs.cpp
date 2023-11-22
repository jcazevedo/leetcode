// 2616. Minimize the Maximum Difference of Pairs
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  bool good(int maxDiff, int p, const vector<int>& nums) {
    int i = 0, c = 0, N = nums.size();
    while (i < N - 1) {
      if (nums[i + 1] - nums[i] <= maxDiff) {
        c++;
        i++;
      }
      i++;
    }
    return c >= p;
  }

public:
  int minimizeMax(vector<int>& nums, int p) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, r = nums[N - 1] - nums[0];
    while (l < r) {
      int m = l + (r - l) / 2;
      if (good(m, p, nums))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
