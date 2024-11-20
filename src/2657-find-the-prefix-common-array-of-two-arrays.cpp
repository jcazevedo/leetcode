// 2657. Find the Prefix Common Array of Two Arrays
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int N = A.size();
    vector<int> cnt(N + 1, 2);
    vector<int> ans(N, 0);
    for (int i = 0; i < N; ++i) {
      if (i > 0) { ans[i] = ans[i - 1]; }
      cnt[A[i]]--;
      if (cnt[A[i]] == 0) { ++ans[i]; }
      cnt[B[i]]--;
      if (cnt[B[i]] == 0) { ++ans[i]; }
    }
    return ans;
  }
};
