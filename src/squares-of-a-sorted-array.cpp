#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    int N = A.size();
    vector<int> res(N);
    int l = 0;
    int r = N - 1;
    int idx = N - 1;
    while (l <= r) {
      if (l == r) {
        res[idx--] = A[r] * A[r];
        r--;
      } else if (A[l] < 0) {
        if (-A[l] > A[r]) {
          res[idx--] = A[l] * A[l];
          l++;
        } else {
          res[idx--] = A[r] * A[r];
          r--;
        }
      } else {
        res[idx--] = A[r] * A[r];
        r--;
      }
    }
    return res;
  }
};
