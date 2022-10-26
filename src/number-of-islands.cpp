#include <vector>

using namespace std;

class Solution {
 private:
  void fill(int i, int j, vector<vector<char>>& grid) {
    if (i < 0 || i >= (int)grid.size() || j < 0 || j >= (int)grid[0].size() || grid[i][j] == '0') return;
    grid[i][j] = '0';
    fill(i + 1, j, grid);
    fill(i - 1, j, grid);
    fill(i, j + 1, grid);
    fill(i, j - 1, grid);
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0) return 0;
    int c = 0;
    for (int i = 0; i < (int)grid.size(); i++) {
      for (int j = 0; j < (int)grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          fill(i, j, grid);
          c++;
        }
      }
    }
    return c;
  }
};
