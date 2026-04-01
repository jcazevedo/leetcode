// 2751. Robot Collisions
// https://leetcode.com/problems/robot-collisions/

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int N = positions.size();
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return positions[a] < positions[b]; });
    vector<int> movingRight;
    for (int i = 0; i < N; ++i) {
      int idx = order[i];
      if (directions[idx] == 'R') {
        movingRight.push_back(idx);
      } else {
        while (!movingRight.empty() && healths[idx] > 0) {
          int curr = movingRight.back();
          movingRight.pop_back();
          if (healths[curr] == healths[idx]) {
            healths[curr] = 0;
            healths[idx] = 0;
          } else if (healths[curr] > healths[idx]) {
            healths[idx] = 0;
            --healths[curr];
            movingRight.push_back(curr);
          } else {
            healths[curr] = 0;
            --healths[idx];
          }
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
      if (healths[i] > 0) { ans.push_back(healths[i]); }
    }
    return ans;
  }
};
