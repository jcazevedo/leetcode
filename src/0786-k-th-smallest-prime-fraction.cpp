// 786. K-th Smallest Prime Fraction
// https://leetcode.com/problems/k-th-smallest-prime-fraction/

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int N = arr.size();
    priority_queue<pair<double, pair<int, int>>> pq;
    for (int i = 0; i < N; ++i) pq.push({-1.0 * arr[i] / arr[N - 1], {i, N - 1}});
    while (--k > 0) {
      pair<int, int> curr = pq.top().second;
      pq.pop();
      pq.push({-1.0 * arr[curr.first] / arr[curr.second - 1], {curr.first, curr.second - 1}});
    }
    pair<int, int> ans = pq.top().second;
    return {arr[ans.first], arr[ans.second]};
  }
};
