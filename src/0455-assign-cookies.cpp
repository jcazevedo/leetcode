// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int G = g.size(), S = s.size();
    int j = 0;
    int ans = 0;
    for (int i = 0; i < G; ++i) {
      while (j < S && s[j] < g[i]) ++j;
      if (j < S && s[j] >= g[i]) {
        ++ans;
        ++j;
      }
    }

    return ans;
  }
};
