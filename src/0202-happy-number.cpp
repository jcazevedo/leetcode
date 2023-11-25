// 202. Happy Number
// https://leetcode.com/problems/happy-number/

#include <set>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    set<int> visited;
    while (true) {
      if (visited.find(n) != visited.end()) return false;
      visited.insert(n);
      int next = 0;
      while (n) {
        int d = n % 10;
        next += d * d;
        n /= 10;
      }
      if (next == 1) return true;
      n = next;
    }
  }
};
