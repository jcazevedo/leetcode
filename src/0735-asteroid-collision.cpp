// 735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/

#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    for (int a : asteroids) {
      bool survived = true;
      while (!s.empty() && (s.top() > 0 && a < 0)) {
        if (abs(s.top()) < abs(a)) {
          s.pop();
          continue;
        } else if (abs(s.top()) == abs(a)) {
          s.pop();
        }
        survived = false;
        break;
      }
      if (survived) { s.push(a); }
    }
    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
