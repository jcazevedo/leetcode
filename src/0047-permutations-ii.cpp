// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    do { ans.push_back(nums); } while (next_permutation(nums.begin(), nums.end()));
    return ans;
  }
};
