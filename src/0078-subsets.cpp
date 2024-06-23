// 78. Subsets
// https://leetcode.com/problems/subsets/

#include <vector>

using namespace std;

class Solution {
 private:
  void aux(vector<int>& nums, vector<bool>& include, int N, vector<vector<int>>& res) {
    if (N == (int)nums.size()) {
      vector<int> n;
      for (int i = 0; i < N; i++) {
        if (include[i]) n.push_back(nums[i]);
      }
      res.push_back(n);
    } else {
      include[N] = true;
      aux(nums, include, N + 1, res);
      include[N] = false;
      aux(nums, include, N + 1, res);
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<bool> include;
    include.assign(nums.size(), false);
    vector<vector<int>> res;
    aux(nums, include, 0, res);
    return res;
  }
};
