// 838. Push Dominoes
// https://leetcode.com/problems/push-dominoes/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size(), curr;
    vector<int> f(n, 0);
    string ans = "";
    curr = 0;
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == 'R') {
        curr = n;
      } else if (dominoes[i] == 'L') {
        curr = 0;
      } else {
        curr = max(curr - 1, 0);
      }
      f[i] += curr;
    }
    curr = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (dominoes[i] == 'L') {
        curr = n;
      } else if (dominoes[i] == 'R') {
        curr = 0;
      } else {
        curr = max(curr - 1, 0);
      }
      f[i] -= curr;
    }
    for (int i = 0; i < n; ++i) {
      if (f[i] > 0) {
        ans += 'R';
      } else if (f[i] < 0) {
        ans += 'L';
      } else {
        ans += '.';
      }
    }
    return ans;
  }
};
