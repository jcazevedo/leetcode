// 2328. Number of Increasing Paths in a Grid
// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
private:
  static vector<vector<int>> directions;

  int pathsEnding(int i, int j, int M, int N, const vector<vector<int>>& grid, vector<vector<int>>& cache) {
    if (cache[i][j] == -1) {
      long long ans = 1;
      for (int d = 0; d < (int)directions.size(); ++d) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < M && nj >= 0 && nj < N && grid[ni][nj] < grid[i][j])
          ans = (ans + pathsEnding(ni, nj, M, N, grid, cache)) % MOD;
      }
      cache[i][j] = ans;
    }
    return cache[i][j];
  }

public:
  int countPaths(vector<vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    vector<vector<int>> cache = vector<vector<int>>(M, vector<int>(N, -1));
    long long ans = 0;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        ans = (ans + pathsEnding(i, j, M, N, grid, cache)) % MOD;
    return ans;
  }
};

vector<vector<int>> Solution::directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
