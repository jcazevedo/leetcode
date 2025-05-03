// 1007. Minimum Domino Rotations For Equal Row
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int N = A.size();
    unordered_map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
      ++cnt[A[i]];
      if (B[i] != A[i]) { ++cnt[B[i]]; }
    }
    int best = -1;
    for (int i = 1; i <= 6; ++i) {
      if (cnt[i] != N) { continue; }
      int curr = 0;
      for (int j = 0; j < N; ++j) {
        if (A[j] != i) { ++curr; }
      }
      if (best == -1 || curr < best) { best = curr; }
      curr = 0;
      for (int j = 0; j < N; ++j) {
        if (B[j] != i) { ++curr; }
      }
      if (best == -1 || curr < best) { best = curr; }
    }
    return best;
  }
};
