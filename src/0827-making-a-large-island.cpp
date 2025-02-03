// 827. Making A Large Island
// https://leetcode.com/problems/making-a-large-island/

#include <set>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

  int visit(int i, int j, int idx, vector<vector<int>>& grid, vector<vector<int>>& visited, int N) {
    if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] == 0 || visited[i][j] != -1) { return 0; }
    int area = 1;
    visited[i][j] = idx;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];
      area += visit(ni, nj, idx, grid, visited, N);
    }
    return area;
  }

 public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> visited(n, vector<int>(n, -1));
    vector<int> areas;
    int islands = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1 && visited[i][j] == -1) {
          int area = visit(i, j, islands, grid, visited, n);
          areas.push_back(area);
          ans = max(ans, area);
          ++islands;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          set<int> neighbors;
          for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && visited[ni][nj] != -1) { neighbors.insert(visited[ni][nj]); }
          }
          int tot_area = 1;
          for (int n : neighbors) { tot_area += areas[n]; }
          ans = max(ans, tot_area);
        }
      }
    }
    return ans;
  }
};

vector<vector<int>> Solution::dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
