// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> ans;
  vector<int> next;

  void dfs(int curr_sum, int next_num, int n_nums, int k, int n) {
    if (n_nums == k) {
      if (curr_sum == n)
        ans.push_back(next);
      return;
    }
    for (int i = next_num; i <= 9; ++i) {
      if (curr_sum + i > n)
        continue;
      next.push_back(i);
      dfs(curr_sum + i, i + 1, n_nums + 1, k, n);
      next.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    ans.clear();
    next.clear();
    dfs(0, 1, 0, k, n);
    return ans;
  }
};
