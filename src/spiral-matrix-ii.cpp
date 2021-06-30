#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(n, -1));
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int i = 0, j, dir = 1, curr = 1, cnt = 0, W = n, H = n;
    for (j = 0; j < n; ++j)
      ans[i][j] = ++cnt;
    --j;
    bool in_height = false;
    int expected = H * W;
    while (cnt < expected) {
      i += dirs[dir].first;
      j += dirs[dir].second;
      ans[i][j] = ++cnt;
      curr++;
      if (in_height && curr >= H) {
        dir = (dir + 1) % 4;
        H = H - 1;
        curr = 1;
        in_height = false;
      } else if (!in_height && curr >= W) {
        dir = (dir + 1) % 4;
        W = W - 1;
        curr = 1;
        in_height = true;
      }
    }
    return ans;
  }
};
