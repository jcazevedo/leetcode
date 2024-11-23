// 3363. Find the Maximum Number of Fruits Collected
// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/

#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  int child1(const vector<vector<int>>& fruits) {
    int N = fruits.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) { ans += fruits[i][i]; }
    return ans;
  }

  int child2(const vector<vector<int>>& fruits) {
    int N = fruits.size();
    vector<vector<int>> best(N, vector<int>(N, numeric_limits<int>::min()));
    queue<vector<int>> q;
    q.push({N - 1, 0});
    best[N - 1][0] = fruits[N - 1][0];
    while (!q.empty()) {
      vector<int> curr = q.front();
      q.pop();
      for (int di = -1; di <= 1; ++di) {
        int ni = curr[0] + di;
        int nj = curr[1] + 1;
        if (ni >= 0 && ni < N && nj < N - 1 && best[curr[0]][curr[1]] + fruits[ni][nj] > best[ni][nj]) {
          best[ni][nj] = best[curr[0]][curr[1]] + fruits[ni][nj];
          q.push({ni, nj});
        }
      }
    }
    return best[N - 1][N - 2];
  }

  int child3(const vector<vector<int>>& fruits) {
    int N = fruits.size();
    vector<vector<int>> best(N, vector<int>(N, numeric_limits<int>::min()));
    queue<vector<int>> q;
    q.push({0, N - 1});
    best[0][N - 1] = fruits[0][N - 1];
    while (!q.empty()) {
      vector<int> curr = q.front();
      q.pop();
      for (int dj = -1; dj <= 1; ++dj) {
        int ni = curr[0] + 1;
        int nj = curr[1] + dj;
        if (nj >= 0 && nj < N && ni < N - 1 && best[curr[0]][curr[1]] + fruits[ni][nj] > best[ni][nj]) {
          best[ni][nj] = best[curr[0]][curr[1]] + fruits[ni][nj];
          q.push({ni, nj});
        }
      }
    }
    return best[N - 2][N - 1];
  }

 public:
  int maxCollectedFruits(vector<vector<int>>& fruits) { return child1(fruits) + child2(fruits) + child3(fruits); }
};
