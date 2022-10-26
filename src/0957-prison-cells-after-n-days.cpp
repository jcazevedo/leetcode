// 957. Prison Cells After N Days
// https://leetcode.com/problems/prison-cells-after-n-days/

#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> next_day(vector<int>& cells) {
    vector<int> res(8, 0);
    for (int i = 1; i < 7; ++i) {
      if (cells[i - 1] + cells[i + 1] != 1) res[i] = 1;
    }
    return res;
  }

 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<vector<int>> cell_days;
    map<vector<int>, int> visited;
    vector<int> curr = cells;
    cell_days.push_back(curr);
    visited[curr] = 0;
    int loop_start = 0;
    while (true) {
      vector<int> next = next_day(curr);
      if (visited.count(next) > 0) {
        loop_start = visited[next];
        break;
      }
      visited[next] = cell_days.size();
      cell_days.push_back(next);
      curr = next;
    }
    if (N < (int)cell_days.size()) return cell_days[N];
    return cell_days[(N - loop_start) % (cell_days.size() - loop_start) + loop_start];
  }
};
