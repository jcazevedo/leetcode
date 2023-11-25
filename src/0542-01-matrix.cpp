// 542. 01 Matrix
// https://leetcode.com/problems/01-matrix/

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> dist =
        vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), -1));
    queue<tuple<int, int>> q;
    for (int i = 0; i < (int)mat.size(); ++i)
      for (int j = 0; j < (int)mat[i].size(); ++j)
        if (mat[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
    int i, j;
    while (!q.empty()) {
      tie(i, j) = q.front();
      q.pop();
      for (const vector<int>& dir : dirs) {
        int ni = i + dir[0];
        int nj = j + dir[1];
        if (ni >= 0 && ni < (int)mat.size() && nj >= 0 &&
            nj < (int)mat[ni].size() &&
            (dist[ni][nj] == -1 || (dist[i][j] + 1 < dist[ni][nj]))) {
          dist[ni][nj] = dist[i][j] + 1;
          q.push({ni, nj});
        }
      }
    }
    return dist;
  }
};

vector<vector<int>> Solution::dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
