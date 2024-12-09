// 3152. Special Array II
// https://leetcode.com/problems/special-array-ii/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int N = nums.size();
    vector<int> cnt(N, 0);
    for (int i = 1; i < N; ++i) {
      cnt[i] = cnt[i - 1];
      if (nums[i] % 2 == nums[i - 1] % 2) { ++cnt[i]; }
    }
    int Q = queries.size();
    vector<bool> ans(Q);
    for (int i = 0; i < Q; ++i) {
      if (queries[i][1] - queries[i][0] == 0) {
        ans[i] = true;
      } else {
        ans[i] = cnt[queries[i][1]] - cnt[queries[i][0]] == 0;
      }
    }
    return ans;
  }
};
