// 2337. Move Pieces to Obtain a String
// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

#include <queue>
#include <string>
#include <utility>

using namespace std;

class Solution {
 public:
  bool canChange(string start, string target) {
    int N = target.size();
    queue<pair<char, int>> sq, tq;
    for (int i = 0; i < N; ++i) {
      if (start[i] != '_') { sq.push({start[i], i}); }
      if (target[i] != '_') { tq.push({target[i], i}); }
    }
    if (sq.size() != tq.size()) { return false; }
    while (!tq.empty()) {
      pair<char, int> t = tq.front();
      tq.pop();
      pair<char, int> s = sq.front();
      sq.pop();
      if (t.first != s.first || (t.first == 'L' && s.second < t.second) || (t.first == 'R' && s.second > t.second)) {
        return false;
      }
    }
    return true;
  }
};
