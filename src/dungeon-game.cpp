#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  bool good(int health, vector<vector<int>> &dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();
    vector<vector<int>> dist(M, vector<int>(N, INT_MIN));
    int start = health + dungeon[0][0];
    if (start <= 0)
      return false;
    dist[0][0] = start;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int m = curr.first;
      int n = curr.second;
      if (m + 1 < M) {
        int next = dist[m][n] + dungeon[m + 1][n];
        if (next > 0 && next > dist[m + 1][n]) {
          dist[m + 1][n] = next;
          q.push({m + 1, n});
        }
      }
      if (n + 1 < N) {
        int next = dist[m][n] + dungeon[m][n + 1];
        if (next > 0 && next > dist[m][n + 1]) {
          dist[m][n + 1] = next;
          q.push({m, n + 1});
        }
      }
    }
    return dist[M - 1][N - 1] > 0;
  }

public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int lo = 1, hi = INT_MAX;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (good(mid, dungeon)) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};
