// 3495. Minimum Operations to Make Array Elements Zero
// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  long long prefixSum(int n) {
    int i = 1, b = 1;
    long long ans = 0;
    while (b <= n) {
      ans += 1LL * (i + 1) / 2 * (min(b * 2 - 1, n) - b + 1);
      ++i;
      b *= 2;
    }
    return ans;
  }

 public:
  long long minOperations(vector<vector<int>>& queries) {
    long long ans = 0;
    for (const vector<int>& query : queries) { ans += (prefixSum(query[1]) - prefixSum(query[0] - 1) + 1) / 2; }
    return ans;
  }
};
