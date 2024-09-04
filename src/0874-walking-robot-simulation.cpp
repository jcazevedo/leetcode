// 874. Walking Robot Simulation
// https://leetcode.com/problems/walking-robot-simulation/

#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<vector<int>> diffs;

 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    set<pair<int, int>> obstacleSet;
    for (vector<int> obstacle : obstacles) { obstacleSet.insert(make_pair(obstacle[0], obstacle[1])); }
    int d = 0, x = 0, y = 0, ans = 0;
    for (const int& command : commands) {
      if (command == -2) {
        d = (d + 4 - 1) % 4;
      } else if (command == -1) {
        d = (d + 1) % 4;
      } else {
        int k = command;
        while (k) {
          int nx = x + diffs[d][0];
          int ny = y + diffs[d][1];
          if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
            x = nx;
            y = ny;
            ans = max(ans, x * x + y * y);
            --k;
          } else {
            k = 0;
          }
        }
      }
    }
    return ans;
  }
};

vector<vector<int>> Solution::diffs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
