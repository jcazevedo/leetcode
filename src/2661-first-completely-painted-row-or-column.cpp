// 2661. First Completely Painted Row or Column
// https://leetcode.com/problems/first-completely-painted-row-or-column/

#include <vector>

using namespace std;

class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int A = arr.size();
    vector<int> rArr(A + 1, 0);
    for (int i = 0; i < A; ++i) { rArr[arr[i]] = i; }
    vector<vector<int>> idxs(A, vector<int>());
    int M = mat.size(), N = mat[0].size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) { idxs[rArr[mat[i][j]]] = {i, j}; }
    }
    vector<int> rowCnt(M, N);
    vector<int> colCnt(N, M);
    for (int i = 0; i < A; ++i) {
      rowCnt[idxs[i][0]]--;
      if (rowCnt[idxs[i][0]] == 0) { return i; }
      colCnt[idxs[i][1]]--;
      if (colCnt[idxs[i][1]] == 0) { return i; }
    }
    return -1;
  }
};
