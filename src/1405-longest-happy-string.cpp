// 1405. Longest Happy String
// https://leetcode.com/problems/longest-happy-string/

#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    string ans = "";
    priority_queue<pair<int, char>> pq;
    if (a > 0) { pq.push(make_pair(a, 'a')); }
    if (b > 0) { pq.push(make_pair(b, 'b')); }
    if (c > 0) { pq.push(make_pair(c, 'c')); }
    while (!pq.empty()) {
      pair<int, char> curr = pq.top();
      pq.pop();
      if (ans.size() >= 2 && ans[ans.size() - 1] == curr.second && ans[ans.size() - 2] == curr.second) {
        if (pq.empty()) { break; }
        pair<int, char> nextCurr = pq.top();
        pq.pop();
        ans += nextCurr.second;
        nextCurr.first -= 1;
        if (nextCurr.first > 0) { pq.push(make_pair(nextCurr.first, nextCurr.second)); }
      } else {
        ans += curr.second;
        curr.first -= 1;
      }
      if (curr.first > 0) { pq.push(make_pair(curr.first, curr.second)); }
    }
    return ans;
  }
};
