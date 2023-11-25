// 1428. Leftmost Column with at Least a One
// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/

#include <vector>

using namespace std;

class BinaryMatrix {
 public:
  int get(int x, int y) {
    // This API is provided for us.
    return -1;
  }

  vector<int> dimensions() { return vector<int>(); }
};

class Solution {
 private:
  int best_at_row(BinaryMatrix& binaryMatrix, int row, int col) {
    int lo = 0, hi = col;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      int v = binaryMatrix.get(row, mid);
      if (v == 1)
        hi = mid;
      else
        lo = mid + 1;
    }
    if (binaryMatrix.get(row, lo) == 0) return -1;
    return lo;
  }

 public:
  int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    vector<int> d = binaryMatrix.dimensions();
    int N = d[0];
    int M = d[1];
    int best = -1;
    for (int i = 0; i < N; ++i) {
      int at_row = best_at_row(binaryMatrix, i, best == -1 ? M - 1 : best - 1);
      if (at_row != -1) best = at_row;
    }
    return best;
  }
};
