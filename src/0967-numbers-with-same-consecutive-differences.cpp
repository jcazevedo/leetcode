// 967. Numbers With Same Consecutive Differences
// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int> visited;
    queue<pair<int, int>> q;
    for (int i = 1; i <= 9; ++i) {
      q.emplace(1, i);
      visited.insert(i);
    }
    vector<int> ans;
    while (!q.empty()) {
      int len, num;
      tie(len, num) = q.front();
      q.pop();
      if (len == N)
        ans.push_back(num);
      else {
        int curr = num % 10;
        if (curr + K <= 9) {
          int next = num * 10 + curr + K;
          if (visited.find(next) == visited.end()) {
            visited.insert(next);
            q.emplace(len + 1, next);
          }
        }
        if (curr - K >= 0) {
          int next = num * 10 + curr - K;
          if (visited.find(next) == visited.end()) {
            visited.insert(next);
            q.emplace(len + 1, next);
          }
        }
      }
    }
    return ans;
  }
};
