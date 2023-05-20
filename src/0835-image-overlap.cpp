// 835. Image Overlap
// https://leetcode.com/problems/image-overlap/

#include <vector>

using namespace std;

class Solution {
public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int L = A.size(), ans = 0;
    for (int di = -L + 1; di < L; ++di) {
      for (int dj = -L + 1; dj < L; ++dj) {
        int curr = 0;
        for (int i = 0; i < L; ++i) {
          for (int j = 0; j < L; ++j) {
            int bi = i + di, bj = j + dj, vb = 0;
            if (bi >= 0 && bi < L && bj >= 0 && bj < L)
              vb = B[bi][bj];
            if (A[i][j] == 1 && vb == 1)
              curr++;
          }
        }
        ans = max(ans, curr);
      }
    }
    return ans;
  }
};
