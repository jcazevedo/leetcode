// 2434. Using a Robot to Print the Lexicographically Smallest String
// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string robotWithString(string s) {
    int n = s.size();
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    for (int i = 0; i < n; ++i) { pq.push({s[i], i}); }
    stack<char> rem;
    string ans = "";
    int last_used = -1;
    while (!pq.empty()) {
      pair<char, int> curr = pq.top();
      pq.pop();
      if (curr.second <= last_used) { continue; }
      while (!rem.empty() && rem.top() <= curr.first) {
        ans += rem.top();
        rem.pop();
      }
      ans += curr.first;
      for (int i = last_used + 1; i < curr.second; ++i) { rem.push(s[i]); }
      last_used = max(last_used, curr.second);
    }
    while (!rem.empty()) {
      ans += rem.top();
      rem.pop();
    }
    return ans;
  }
};
