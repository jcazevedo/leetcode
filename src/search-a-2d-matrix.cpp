#include <vector>

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int lo = 0, hi = m - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (matrix[mid][0] > target)
        hi = mid - 1;
      else
        lo = mid;
    }
    if (lo >= m) return false;
    if (matrix[lo][0] > target) return false;
    int i = lo;
    lo = 0;
    hi = n;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (matrix[i][mid] < target)
        lo = mid + 1;
      else
        hi = mid;
    }
    if (lo >= n) return false;
    return matrix[i][lo] == target;
  }
};
