// 1232. Check If It Is a Straight Line
// https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int N = coordinates.size();
    bool parToX = true, parToY = true;
    int x = coordinates[0][0], y = coordinates[0][1];
    for (int i = 1; i < N; ++i) {
      if (x != coordinates[i][0]) parToY = false;
      if (y != coordinates[i][1]) parToX = false;
    }
    if (parToX || parToY) return true;
    double EPS = 0.0000001;
    double dx = coordinates[1][0] - coordinates[0][0];
    double dy = coordinates[1][1] - coordinates[0][1];
    double fixed_rate = dy / dx;
    for (int i = 2; i < N; ++i) {
      double ndx = coordinates[i][0] - coordinates[0][0];
      double ndy = coordinates[i][1] - coordinates[0][1];
      if (abs(fixed_rate - (ndy / ndx)) > EPS) return false;
    }
    return true;
  }
};
