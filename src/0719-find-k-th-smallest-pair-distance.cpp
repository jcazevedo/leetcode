// 719. Find K-th Smallest Pair Distance
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int maxV = nums[N - 1] - nums[0];
    vector<int> diffs(maxV + 1, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) { ++diffs[nums[j] - nums[i]]; }
    }
    int d;
    for (d = 0; d <= maxV; ++d) {
      k -= diffs[d];
      if (k <= 0) { break; }
    }
    return d;
  }
};
