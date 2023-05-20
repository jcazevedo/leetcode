// 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int N = nums.size();
    set<vector<int>> acc;
    for (int i = 0; i < 1 << N; ++i) {
      vector<int> curr;
      for (int j = 0; j < N; ++j) {
        if ((1 << j) & i)
          curr.push_back(nums[j]);
      }
      sort(curr.begin(), curr.end());
      acc.insert(curr);
    }
    vector<vector<int>> ans;
    for (vector<int> subset : acc) {
      ans.push_back(subset);
    }
    return ans;
  }
};
