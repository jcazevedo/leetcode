// 3740. Minimum Distance Between Three Equal Elements I
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    int ans = 2 * n;
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) { idx[nums[i]].push_back(i); }
    for (unordered_map<int, vector<int>>::iterator it = idx.begin(); it != idx.end(); ++it) {
      vector<int>& pos = it->second;
      for (int i = 0; i + 2 < (int)pos.size(); i++) { ans = min(ans, 2 * (pos[i + 2] - pos[i])); }
    }
    return ans == 2 * n ? -1 : ans;
  }
};
