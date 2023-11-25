// 77. Combinations
// https://leetcode.com/problems/combinations/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    for (int i = 1; i < 1 << n; ++i) {
      if (__builtin_popcount(i) == k) {
        vector<int> combination;
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j)) { combination.push_back(j + 1); }
        }
        ans.push_back(combination);
      }
    }
    return ans;
  }
};
