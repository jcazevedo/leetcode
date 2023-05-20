#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    double EPS = 0.0000001;
    double dx = coordinates[1][0] - coordinates[0][0];
    double dy = coordinates[1][1] - coordinates[0][1];
    double fixed_rate = dy / dx;
    int N = coordinates.size();
    for (int i = 2; i < N; ++i) {
      double ndx = coordinates[i][0] - coordinates[0][0];
      double ndy = coordinates[i][1] - coordinates[0][1];
      if (abs(fixed_rate - (ndy / ndx)) > EPS)
        return false;
    }
    return true;
  }
};
