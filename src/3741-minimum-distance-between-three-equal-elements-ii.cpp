// 3741. Minimum Distance Between Three Equal Elements II
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDistance(vector<int>& nums) {
    int n = nums.size();
    int ans = 2 * n;
    unordered_map<int, vector<int>> last;
    for (int i = 0; i < n; i++) {
      vector<int>& w = last[nums[i]];
      w.push_back(i);
      if (w.size() > 3) { w.erase(w.begin()); }
      if (w.size() == 3) { ans = min(ans, 2 * (w[2] - w[0])); }
    }
    return ans == 2 * n ? -1 : ans;
  }
};
