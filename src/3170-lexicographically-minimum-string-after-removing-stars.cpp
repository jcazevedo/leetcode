// 3170. Lexicographically Minimum String After Removing Stars
// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/

#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string clearStars(string s) {
    int n = s.size();
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    vector<bool> deleted(n, false);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        deleted[i] = true;
        if (!pq.empty()) {
          deleted[-pq.top().second] = true;
          pq.pop();
        }
      } else {
        pq.push({s[i], -i});
      }
    }
    string ans = "";
    for (int i = 0; i < n; ++i) {
      if (deleted[i]) { continue; }
      ans += s[i];
    }
    return ans;
  }
};
