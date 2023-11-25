// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestMountain(vector<int>& A) {
    if (A.size() < 3) return 0;
    int N = A.size();
    int best = 0;
    int curr = 1;
    bool increasing = true;
    for (int i = 1; i < N; ++i) {
      if (increasing && A[i] > A[i - 1]) {
        curr++;
      } else if (increasing && curr > 1 && A[i] < A[i - 1]) {
        curr++;
        increasing = false;
      } else if (!increasing && A[i] < A[i - 1]) {
        curr++;
      } else {
        if (!increasing) best = max(curr, best);
        if (A[i] > A[i - 1])
          curr = 2;
        else
          curr = 1;
        increasing = true;
      }
    }
    if (!increasing) best = max(curr, best);
    return best;
  }
};
