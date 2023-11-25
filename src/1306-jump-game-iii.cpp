// 1306. Jump Game III
// https://leetcode.com/problems/jump-game-iii/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    if (arr[start] == 0) return true;
    int N = arr.size();
    vector<bool> can_reach = vector<bool>(N + 1, false);
    can_reach[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      int next_l = curr - arr[curr];
      int next_r = curr + arr[curr];
      if (next_l >= 0 && !can_reach[next_l]) {
        if (arr[next_l] == 0) return true;
        can_reach[next_l] = true;
        q.push(next_l);
      }
      if (next_r < N && !can_reach[next_r]) {
        if (arr[next_r] == 0) return true;
        can_reach[next_r] = true;
        q.push(next_r);
      }
    }
    return false;
  }
};
