// 454. 4Sum II
// https://leetcode.com/problems/4sum-ii/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A,
                   vector<int>& B,
                   vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> ab_sum, cd_sum;
    int N = A.size();
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ab_sum[A[i] + B[j]]++;
        cd_sum[C[i] + D[j]]++;
      }
    }
    int ans = 0;
    for (auto itr = ab_sum.begin(); itr != ab_sum.end(); ++itr) {
      ans += itr->second * cd_sum[-itr->first];
    }
    return ans;
  }
};
