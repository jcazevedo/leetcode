// 3548. Equal Sum Grid Partition II
// https://leetcode.com/problems/equal-sum-grid-partition-ii/

#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    long long sum = 0, acc;
    unordered_map<long long, set<int>> rows, cols;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sum += grid[i][j];
        rows[grid[i][j]].insert(i);
        cols[grid[i][j]].insert(j);
      }
    }
    acc = 0L;
    for (int i = 0; i < m - 1; ++i) {
      for (int j = 0; j < n; ++j) { acc += grid[i][j]; }
      long long bot = sum - acc;
      if (acc == bot) { return true; }
      long long diff = acc - bot;
      if (diff > 0) {
        if (i == 0 || n == 1) {
          if (i == 0 && (grid[i][0] == diff || grid[i][n - 1] == diff)) { return true; }
          if (n == 1 && (grid[0][0] == diff || grid[i][0] == diff)) { return true; }
        } else {
          if (!rows[diff].empty() && *rows[diff].begin() <= i) { return true; }
        }
      } else {
        diff = -diff;
        if (i == m - 2 || n == 1) {
          if (i == m - 2 && (grid[i + 1][0] == diff || grid[i + 1][n - 1] == diff)) { return true; }
          if (n == 1 && (grid[i + 1][0] == diff || grid[m - 1][0] == diff)) { return true; }
        } else {
          if (!rows[diff].empty() && *rows[diff].rbegin() > i) { return true; }
        }
      }
    }
    acc = 0L;
    for (int j = 0; j < n - 1; ++j) {
      for (int i = 0; i < m; ++i) { acc += grid[i][j]; }
      long long right = sum - acc;
      if (acc == right) { return true; }
      long long diff = acc - right;
      if (diff > 0) {
        if (j == 0 || m == 1) {
          if (j == 0 && (grid[0][j] == diff || grid[m - 1][j] == diff)) { return true; }
          if (m == 1 && (grid[0][0] == diff || grid[0][j] == diff)) { return true; }
        } else {
          if (!cols[diff].empty() && *cols[diff].begin() <= j) { return true; }
        }
      } else {
        diff = -diff;
        if (j == n - 2 || m == 1) {
          if (j == n - 2 && (grid[0][j + 1] == diff || grid[m - 1][j + 1] == diff)) { return true; }
          if (m == 1 && (grid[0][j + 1] == diff || grid[0][n - 1] == diff)) { return true; }
        } else {
          if (!cols[diff].empty() && *cols[diff].rbegin() > j) { return true; }
        }
      }
    }
    return false;
  }
};
