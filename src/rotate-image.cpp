#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    for (int i = 0; i < N / 2; ++i) {
      for (int j = i; j < N - i - 1; ++j) {
        int& v1 = matrix[i][j];
        int& v2 = matrix[j][N - i - 1];
        int& v3 = matrix[N - i - 1][N - j - 1];
        int& v4 = matrix[N - j - 1][i];
        swap(v1, v2);
        swap(v1, v3);
        swap(v1, v4);
      }
    }
  }
};
