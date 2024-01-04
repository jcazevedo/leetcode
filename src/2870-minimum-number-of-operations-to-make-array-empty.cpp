// 2870. Minimum Number of Operations to Make Array Empty
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

#include <algorithm>
#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAXN 1000000

vector<long long> ops;

void dp() {
  ops = vector<long long>(MAXN + 1, numeric_limits<int>::max());
  ops[0] = 0L;
  for (int i = 1; i <= MAXN; ++i) {
    if (i - 2 >= 0) ops[i] = min(ops[i], ops[i - 2] + 1L);
    if (i - 3 >= 0) ops[i] = min(ops[i], ops[i - 3] + 1L);
  }
}

class Solution {
 public:
  int minOperations(vector<int>& nums) {
    if (ops.empty()) dp();

    unordered_map<int, int> cnts;
    for (int v : nums) cnts[v]++;

    int ans = 0;
    for (auto itr = cnts.begin(); itr != cnts.end(); ++itr) {
      int v = ops[itr->second];
      if (v == numeric_limits<int>::max()) return -1;
      ans += v;
    }

    return ans;
  }
};
