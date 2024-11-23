// 3355. Zero Array Transformation I
// https://leetcode.com/problems/zero-array-transformation-i/

#include <vector>

using namespace std;

class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size(), Q = queries.size();
    vector<int> intervalStart(N, 0);
    vector<int> intervalEnd(N, 0);
    for (int q = 0; q < Q; ++q) {
      ++intervalStart[queries[q][0]];
      ++intervalEnd[queries[q][1]];
    }
    int curr = 0;
    for (int i = 0; i < N; ++i) {
      curr += intervalStart[i];
      nums[i] -= curr;
      curr -= intervalEnd[i];
    }
    for (int i = 0; i < N; ++i) {
      if (nums[i] > 0) { return false; }
    }
    return true;
  }
};
