// 1553. Minimum Number of Days to Eat N Oranges
// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
  int minDays(int n) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push(make_pair(n, 0));
    visited.insert(n);
    while (!q.empty()) {
      pair<int, int> curr = q.front();
      q.pop();
      int oranges = curr.first;
      int days = curr.second;
      if (oranges == 0)
        return days;
      if (oranges % 2 == 0 && visited.find(oranges / 2) == visited.end()) {
        visited.insert(oranges / 2);
        q.push(make_pair(oranges / 2, days + 1));
      }
      if (oranges % 3 == 0 && visited.find(oranges - 2 * (oranges / 3)) == visited.end()) {
        visited.insert(oranges - 2 * (oranges / 3));
        q.push(make_pair(oranges - 2 * (oranges / 3), days + 1));
      }
      if (visited.find(oranges - 1) == visited.end()) {
        visited.insert(oranges - 1);
        q.push(make_pair(oranges - 1, days + 1));
      }
    }
    return n;
  }
};
