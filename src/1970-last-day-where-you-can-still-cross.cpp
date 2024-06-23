// 1970. Last Day Where You Can Still Cross
// https://leetcode.com/problems/last-day-where-you-can-still-cross/

#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  bool floodFill(int i, int j, int row, int col, set<pair<int, int>>& visited) {
    if (i == row - 1) return true;
    for (int d = 0; d < (int)directions.size(); ++d) {
      int ni = i + directions[d][0];
      int nj = j + directions[d][1];
      if (ni >= 0 && ni < row && nj >= 0 && nj < col && visited.find(make_pair(ni, nj)) == visited.end()) {
        visited.insert(make_pair(ni, nj));
        if (floodFill(ni, nj, row, col, visited)) return true;
      }
    }
    return false;
  }

  bool canCross(int row, int col, const vector<vector<int>>& cells, int day) {
    set<pair<int, int>> visited;
    for (int i = 0; i < day; ++i) visited.insert(make_pair(cells[i][0] - 1, cells[i][1] - 1));
    for (int i = 0; i < col; ++i) {
      if (visited.find(make_pair(0, i)) == visited.end()) {
        visited.insert(make_pair(0, i));
        if (floodFill(0, i, row, col, visited)) return true;
      }
    }
    return false;
  }

 public:
  int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    int lo = 0, hi = cells.size();
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (canCross(row, col, cells, mid))
        lo = mid;
      else
        hi = mid - 1;
    }
    return lo;
  }
};
