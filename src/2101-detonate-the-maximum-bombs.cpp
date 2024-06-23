// 2101. Detonate the Maximum Bombs
// https://leetcode.com/problems/detonate-the-maximum-bombs/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  bool inCircle(long long x, long long y, long long cx, long long cy, long long radius) {
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= radius * radius;
  }

 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int N = bombs.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      vector<bool> visited = vector<bool>(N, false);
      queue<int> q;
      q.push(i);
      visited[i] = true;
      int detonations = 1;
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int j = 0; j < N; ++j) {
          if (visited[j]) continue;
          if (inCircle(bombs[j][0], bombs[j][1], bombs[curr][0], bombs[curr][1], bombs[curr][2])) {
            visited[j] = true;
            q.push(j);
            detonations += 1;
          }
        }
      }
      ans = max(ans, detonations);
    }
    return ans;
  }
};
