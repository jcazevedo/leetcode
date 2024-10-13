// 632. Smallest Range Covering Elements from K Lists
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int N = nums.size();
    vector<int> idx(N, 0);
    vector<long long> ans = {numeric_limits<int>::min(), numeric_limits<int>::max()};
    while (true) {
      int minV = numeric_limits<int>::max();
      int maxV = numeric_limits<int>::min();
      int minIdx = 0;
      for (int i = 0; i < N; ++i) {
        int curr = nums[i][idx[i]];
        if (curr < minV) {
          minV = curr;
          minIdx = i;
        }
        if (curr > maxV) { maxV = curr; }
      }
      if (maxV - minV < ans[1] - ans[0]) { ans = {minV, maxV}; }
      if (++idx[minIdx] == (int)nums[minIdx].size()) { break; }
    }
    return {(int)ans[0], (int)ans[1]};
  }
};
