// 1310. XOR Queries of a Subarray
// https://leetcode.com/problems/xor-queries-of-a-subarray/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int N = arr.size();
    vector<int> xorUntil(N, 0);
    xorUntil[0] = arr[0];
    for (int i = 1; i < N; ++i) { xorUntil[i] = xorUntil[i - 1] ^ arr[i]; }
    int Q = queries.size();
    vector<int> ans(Q);
    for (int i = 0; i < Q; ++i) {
      ans[i] = xorUntil[queries[i][1]];
      if (queries[i][0] > 0) { ans[i] = ans[i] ^ xorUntil[queries[i][0] - 1]; }
    }
    return ans;
  }
};
