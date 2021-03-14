#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isRobotBounded(string instructions) {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0;
    pair<int, int> curr = {0, 0};
    for (char inst : instructions) {
      if (inst == 'G') {
        curr.first += dirs[dir].first;
        curr.second += dirs[dir].second;
      } else if (inst == 'R') {
        dir = (dir + 1) % 4;
      } else if (inst == 'L') {
        dir = (4 + dir - 1) % 4;
      }
    }
    return dir != 0 || (curr.first == 0 && curr.second == 0);
  }
};
