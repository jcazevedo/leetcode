// 3286. Find a Safe Walk Through a Grid
// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/

#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 private:
  static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int rows = grid.size();
    int cols = grid[0].size();
    int startHealth = health - grid[0][0];
    if (startHealth <= 0) { return false; }
    vector<vector<int>> bestHealth(rows, vector<int>(cols, -1));
    queue<tuple<int, int, int>> q;
    bestHealth[0][0] = startHealth;
    q.push({0, 0, startHealth});
    while (!q.empty()) {
      tuple<int, int, int> current = q.front();
      int row = get<0>(current);
      int col = get<1>(current);
      int remainingHealth = get<2>(current);
      q.pop();
      if (row == rows - 1 && col == cols - 1) { return true; }
      for (int direction = 0; direction < 4; ++direction) {
        int nextRow = row + dirs[direction][0];
        int nextCol = col + dirs[direction][1];
        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) { continue; }
        int nextHealth = remainingHealth - grid[nextRow][nextCol];
        if (nextHealth <= 0 || nextHealth <= bestHealth[nextRow][nextCol]) { continue; }
        bestHealth[nextRow][nextCol] = nextHealth;
        q.push({nextRow, nextCol, nextHealth});
      }
    }
    return false;
  }
};
