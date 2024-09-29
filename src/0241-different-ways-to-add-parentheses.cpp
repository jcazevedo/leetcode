// 241. Different Ways to Add Parentheses
// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <cstdio>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> go(int l, int r, const string& expression, vector<vector<vector<int>>>& cache) {
    if (!cache[l][r].empty()) { return cache[l][r]; }
    vector<int> ans;
    int d = 0;
    for (int i = l; i <= r; ++i) {
      if (!isdigit(expression[i])) {
        vector<int> left = go(l, i - 1, expression, cache);
        vector<int> right = go(i + 1, r, expression, cache);
        for (int lv : left) {
          for (int rv : right) {
            switch (expression[i]) {
              case '+':
                ans.push_back(lv + rv);
                break;
              case '-':
                ans.push_back(lv - rv);
                break;
              case '*':
                ans.push_back(lv * rv);
                break;
            }
          }
        }
      } else {
        d *= 10;
        d += (expression[i] - '0');
      }
    }
    if (ans.empty()) { ans.push_back(d); }
    cache[l][r] = ans;
    return ans;
  }

 public:
  vector<int> diffWaysToCompute(string expression) {
    int N = expression.size();
    vector<vector<vector<int>>> cache(N, vector<vector<int>>(N, vector<int>()));
    return go(0, N - 1, expression, cache);
  }
};
