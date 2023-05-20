#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    int H = A.size();
    int W = A[0].size();
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W / 2; ++j) {
        int tmp = A[i][j];
        A[i][j] = A[i][W - 1 - j];
        A[i][W - 1 - j] = tmp;
      }
      for (int j = 0; j < W; ++j) {
        A[i][j] = A[i][j] ? 0 : 1;
      }
    }
    return A;
  }
};
