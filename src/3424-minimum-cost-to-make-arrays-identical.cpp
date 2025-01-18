// 3424. Minimum Cost to Make Arrays Identical
// https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
    int N = arr.size();
    if (arr == brr) { return 0; }
    long long ans = numeric_limits<long long>::max();
    long long curr = 0L;
    for (int i = 0; i < N; ++i) { curr += abs(arr[i] - brr[i]); }
    ans = min(ans, curr);
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    curr = k;
    for (int i = 0; i < N; ++i) { curr += abs(arr[i] - brr[i]); }
    ans = min(ans, curr);
    return ans;
  }
};
