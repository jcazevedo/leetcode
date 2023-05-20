#include <cstring>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define MAXN 500

class Solution {
private:
  int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int visited[MAXN][MAXN];
  int area[MAXN * MAXN];
  int N;

  int visit(vector<vector<int>>& grid, int i, int j, int idx) {
    if (i < 0 || i >= N || j < 0 || j >= N || grid[i][j] == 0 || visited[i][j] != 0)
      return 0;
    int area = 1;
    visited[i][j] = idx;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dirs[d][0];
      int nj = j + dirs[d][1];
      area += visit(grid, ni, nj, idx);
    }
    return area;
  }

public:
  int largestIsland(vector<vector<int>>& grid) {
    N = grid.size();
    memset(visited, 0, sizeof(visited));
    int islands = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == 1 && visited[i][j] == 0) {
          int curr_area = visit(grid, i, j, ++islands);
          area[islands] = curr_area;
          ans = max(ans, curr_area);
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (grid[i][j] == 0) {
          set<int> neighbors;
          for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && visited[ni][nj] != 0)
              neighbors.insert(visited[ni][nj]);
          }
          int tot_area = 1;
          for (int n : neighbors)
            tot_area += area[n];
          ans = max(ans, tot_area);
        }
      }
    }
    return ans;
  }
};
