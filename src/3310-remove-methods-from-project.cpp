// 3310. Remove Methods From Project
// https://leetcode.com/problems/remove-methods-from-project/

#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> graph(n);
    for (const vector<int>& invocation : invocations) { graph[invocation[0]].push_back(invocation[1]); }
    vector<bool> suspicious(n, false);
    stack<int> s;
    s.push(k);
    suspicious[k] = true;
    while (!s.empty()) {
      int method = s.top();
      s.pop();
      for (int invoked : graph[method]) {
        if (!suspicious[invoked]) {
          suspicious[invoked] = true;
          s.push(invoked);
        }
      }
    }
    for (const vector<int>& invocation : invocations) {
      if (!suspicious[invocation[0]] && suspicious[invocation[1]]) {
        vector<int> remaining(n);
        for (int method = 0; method < n; ++method) { remaining[method] = method; }
        return remaining;
      }
    }
    vector<int> remaining;
    for (int method = 0; method < n; ++method) {
      if (!suspicious[method]) { remaining.push_back(method); }
    }
    return remaining;
  }
};
