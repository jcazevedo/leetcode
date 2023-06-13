// 2352. Equal Row and Column Pairs
// https://leetcode.com/problems/equal-row-and-column-pairs/

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int N = grid.size();
    map<vector<int>, int> rows;
    for (int i = 0; i < N; ++i) {
      vector<int> row;
      for (int j = 0; j < N; ++j) {
        row.push_back(grid[i][j]);
      }
      rows[row]++;
    }
    int ans = 0;
    for (int j = 0; j < N; ++j) {
      vector<int> col;
      for (int i = 0; i < N; ++i) {
        col.push_back(grid[i][j]);
      }
      ans += rows[col];
    }
    return ans;
  }
};
