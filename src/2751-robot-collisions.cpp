// 2751. Robot Collisions
// https://leetcode.com/problems/robot-collisions/

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int N = positions.size();
    vector<vector<int>> inPosOrder;
    for (int i = 0; i < N; ++i) { inPosOrder.push_back({positions[i], i}); }
    sort(inPosOrder.begin(), inPosOrder.end());
    stack<int> movingRight;
    for (int i = 0; i < N; ++i) {
      int idx = inPosOrder[i][1];
      if (directions[idx] == 'R') {
        movingRight.push(idx);
      } else {
        while (!movingRight.empty() && healths[idx] > 0) {
          int curr = movingRight.top();
          movingRight.pop();
          if (healths[curr] == healths[idx]) {
            healths[curr] = 0;
            healths[idx] = 0;
          } else if (healths[curr] > healths[idx]) {
            healths[idx] = 0;
            --healths[curr];
            if (healths[curr] != 0) { movingRight.push(curr); }
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
