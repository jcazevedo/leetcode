// 3356. Zero Array Transformation II
// https://leetcode.com/problems/zero-array-transformation-ii/

#include <vector>

using namespace std;

class Solution {
 private:
  bool good(vector<int> nums, vector<vector<int>>& queries, int k) {
    int N = nums.size();
    vector<int> intervalStart(N, 0);
    vector<int> intervalEnd(N, 0);
    for (int q = 0; q < k; ++q) {
      intervalStart[queries[q][0]] += queries[q][2];
      intervalEnd[queries[q][1]] += queries[q][2];
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

 public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int Q = queries.size();
    int lo = 0, hi = Q;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(nums, queries, mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (!good(nums, queries, lo)) { return -1; }
    return lo;
  }
};
