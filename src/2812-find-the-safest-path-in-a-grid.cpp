// 2812. Find the Safest Path in a Grid
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> dirs;

  void floodFill(int i, int j, int N, vector<vector<int>>& minDistToThief) {
    for (const vector<int>& dir : dirs) {
      int di = i + dir[0];
      int dj = j + dir[1];
      if (di >= 0 && di < N && dj >= 0 && dj < N &&
          minDistToThief[di][dj] > minDistToThief[i][j] + 1) {
        minDistToThief[di][dj] = minDistToThief[i][j] + 1;
        floodFill(di, dj, N, minDistToThief);
      }
    }
  }

 public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    int N = grid.size();

    vector<vector<int>> minDistToThief(N, vector<int>(N, -1));
    queue<vector<int>> q;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (grid[i][j] == 1) {
          q.push({i, j});
          minDistToThief[i][j] = 0;
        }
    while (!q.empty()) {
      int len = q.size();
      while (len-- > 0) {
        vector<int> curr = q.front();
        q.pop();
        int i = curr[0];
        int j = curr[1];
        for (const vector<int>& dir : dirs) {
          int di = i + dir[0];
          int dj = j + dir[1];
          if (di >= 0 && di < N && dj >= 0 && dj < N &&
              minDistToThief[di][dj] == -1) {
            minDistToThief[di][dj] = minDistToThief[i][j] + 1;
            q.push({di, dj});
          }
        }
      }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    priority_queue<vector<int>> pq;
    pq.push({minDistToThief[0][0], 0, 0});
    while (!pq.empty()) {
      vector<int> curr = pq.top();
      pq.pop();
      int maxDist = curr[0];
      int i = curr[1];
      int j = curr[2];
      if (i == N - 1 && j == N - 1) return maxDist;
      for (const vector<int>& dir : dirs) {
        int di = i + dir[0];
        int dj = j + dir[1];
        if (di >= 0 && di < N && dj >= 0 && dj < N && !visited[di][dj]) {
          pq.push({min(maxDist, minDistToThief[di][dj]), di, dj});
          visited[di][dj] = true;
        }
      }
    }
    return -1;
  }
};

vector<vector<int>> Solution::dirs = {{0, +1}, {0, -1}, {+1, 0}, {-1, 0}};
