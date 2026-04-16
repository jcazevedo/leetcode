// 3488. Closest Equal Element Queries
// https://leetcode.com/problems/closest-equal-element-queries/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    unordered_map<int, vector<int>> positions;
    for (int i = 0; i < n; ++i) { positions[nums[i]].push_back(i); }
    vector<int> minDist(n, -1);
    for (unordered_map<int, vector<int>>::iterator it = positions.begin(); it != positions.end(); ++it) {
      vector<int>& pos = it->second;
      int k = pos.size();
      if (k < 2) { continue; }
      for (int i = 0; i < k; ++i) {
        int prev = pos[(i - 1 + k) % k];
        int next = pos[(i + 1) % k];
        int dPrev = min(abs(pos[i] - prev), n - abs(pos[i] - prev));
        int dNext = min(abs(pos[i] - next), n - abs(pos[i] - next));
        minDist[pos[i]] = min(dPrev, dNext);
      }
    }
    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) { ans[i] = minDist[queries[i]]; }
    return ans;
  }
};
