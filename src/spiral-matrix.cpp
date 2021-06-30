#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int H = matrix.size();
    if (H == 0)
      return {};
    int W = matrix[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    for (int i = 0; i < W; ++i)
      res.push_back(matrix[0][i]);
    int cnt = W;
    int i = 0, j = W - 1, dir = 1, curr = 1;
    bool in_height = true;
    int expected = H * W;
    while (cnt < expected) {
      i += dirs[dir].first;
      j += dirs[dir].second;
      res.push_back(matrix[i][j]);
      cnt++;
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
    return res;
  }
};
