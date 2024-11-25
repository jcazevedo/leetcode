// 773. Sliding Puzzle
// https://leetcode.com/problems/sliding-puzzle/

#include <cmath>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
    map<vector<vector<int>>, int> dist;
    queue<vector<vector<int>>> q;
    dist[board] = 0;
    q.push(board);
    while (!q.empty()) {
      vector<vector<int>> curr = q.front();
      q.pop();
      int currDist = dist[curr];
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
          if (curr[i][j] != 0) { continue; }
          for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
              if (abs(di) + abs(dj) != 1 || i + di < 0 || i + di >= 2 || j + dj < 0 || j + dj >= 3) { continue; }
              vector<vector<int>> next = curr;
              next[i][j] = next[i + di][j + dj];
              next[i + di][j + dj] = 0;
              if (dist.find(next) == dist.end() || currDist + 1 < dist[next]) {
                dist[next] = currDist + 1;
                q.push(next);
              }
            }
          }
        }
      }
    }
    if (dist.find(target) == dist.end()) { return -1; }
    return dist[target];
  }
};
