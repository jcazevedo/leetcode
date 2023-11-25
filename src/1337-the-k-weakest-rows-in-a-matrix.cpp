// 1337. The K Weakest Rows in a Matrix
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> rows;
    for (int i = 0; i < m; ++i) {
      int soldiers = 0;
      for (int j = 0; j < n && mat[i][j] == 1; ++j) soldiers++;
      rows.push_back(make_pair(soldiers, i));
    }
    sort(rows.begin(), rows.end());
    vector<int> ans;
    for (int i = 0; i < k; ++i) ans.push_back(rows[i].second);
    return ans;
  }
};
