// 1590. Make Sum Divisible by P
// https://leetcode.com/problems/make-sum-divisible-by-p/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    int N = nums.size();
    int tot = 0;
    for (int i = 0; i < N; ++i) { tot = (tot + nums[i]) % p; }
    if (tot == 0) { return 0; }
    unordered_map<int, int> modIdx;
    modIdx[0] = -1;
    int curr = 0;
    int ans = -1;
    for (int i = 0; i < N; ++i) {
      curr = (curr + nums[i]) % p;
      int rem = (curr - tot + p) % p;
      if (modIdx.find(rem) != modIdx.end()) {
        if (ans == -1 || ans > i - modIdx[rem]) { ans = i - modIdx[rem]; }
      }
      modIdx[curr] = i;
    }
    return ans != N ? ans : -1;
  }
};
