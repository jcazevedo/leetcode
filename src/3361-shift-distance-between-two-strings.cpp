// 3361. Shift Distance Between Two Strings
// https://leetcode.com/problems/shift-distance-between-two-strings/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
    long long ans = 0;
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      if (s[i] != t[i]) {
        long long next = 0;
        char curr = s[i];
        while (curr != t[i]) {
          next += nextCost[curr - 'a'];
          curr = ((curr - 'a') + 1) % 26 + 'a';
        }
        long long prev = 0;
        curr = s[i];
        while (curr != t[i]) {
          prev += previousCost[curr - 'a'];
          curr = ((curr - 'a') + 26 - 1) % 26 + 'a';
        }
        ans += min(next, prev);
      }
    }
    return ans;
  }
};
