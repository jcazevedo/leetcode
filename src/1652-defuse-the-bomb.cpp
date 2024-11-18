// 1652. Defuse the Bomb
// https://leetcode.com/problems/defuse-the-bomb/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int N = code.size();
    vector<int> prefixSum(N * 3);
    prefixSum[0] = code[0];
    for (int i = 1; i < N * 3; ++i) { prefixSum[i] = prefixSum[i - 1] + code[i % N]; }
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      if (k < 0) {
        ans[i] = prefixSum[i + N - 1] - prefixSum[i + N + k - 1];
      } else {
        ans[i] = prefixSum[i + N + k] - prefixSum[i + N];
      }
    }
    return ans;
  }
};
