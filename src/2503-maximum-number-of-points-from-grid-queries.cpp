// 2503. Maximum Number of Points From Grid Queries
// https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int k = queries.size();
    vector<pair<int, int>> indexedQueries;
    for (int i = 0; i < k; ++i) { indexedQueries.push_back({queries[i], i}); }
    sort(indexedQueries.begin(), indexedQueries.end());
    vector<int> ans(k);
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});
    visited[0][0] = true;
    int tot = 0;
    for (int i = 0; i < k; ++i) {
      while (!pq.empty() && pq.top()[0] < indexedQueries[i].first) {
        ++tot;
        vector<int> curr = pq.top();
        int ci = curr[1];
        int cj = curr[2];
        pq.pop();
        for (int di = -1; di <= 1; ++di) {
          int ni = ci + di;
          if (ni < 0 || ni >= m) { continue; }
          for (int dj = -1; dj <= 1; ++dj) {
            int nj = cj + dj;
            if (nj < 0 || nj >= n) { continue; }
            if (abs(di) + abs(dj) != 1) { continue; }
            if (visited[ni][nj]) { continue; }
            visited[ni][nj] = true;
            pq.push({grid[ni][nj], ni, nj});
          }
        }
      }
      ans[indexedQueries[i].second] = tot;
    }
    return ans;
  }
};
