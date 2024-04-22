// 752. Open the Lock
// https://leetcode.com/problems/open-the-lock/

#include <queue>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadendSet;
    for (const string& deadend : deadends) { deadendSet.insert(deadend); }
    unordered_set<string> visited;
    string start = "0000";
    if (deadendSet.find(start) != deadendSet.end()) { return -1; }
    if (target == start) { return 0; }
    queue<tuple<string, int>> q;
    visited.insert(start);
    q.push({start, 0});
    while (!q.empty()) {
      string curr;
      int dist;
      tie(curr, dist) = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        string next = curr;
        int vUp = ((curr[i] - '0') + 1) % 10;
        int vDown = (((curr[i] - '0') + 10 - 1)) % 10;
        next[i] = (vUp + '0');
        if (next == target) { return dist + 1; }
        if (deadendSet.find(next) == deadendSet.end() &&
            visited.find(next) == visited.end()) {
          visited.insert(next);
          q.push({next, dist + 1});
        }
        next[i] = (vDown + '0');
        if (next == target) { return dist + 1; }
        if (deadendSet.find(next) == deadendSet.end() &&
            visited.find(next) == visited.end()) {
          visited.insert(next);
          q.push({next, dist + 1});
        }
      }
    }
    return -1;
  }
};
