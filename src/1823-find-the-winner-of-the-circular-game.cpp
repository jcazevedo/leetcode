// 1823. Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

#include <vector>

using namespace std;

class Solution {
 public:
  int findTheWinner(int n, int k) {
    vector<int> friends(n, 0);
    for (int i = 0; i < n; ++i) friends[i] = i;
    int f = 0;
    while (friends.size() > 1) {
      int next = (f + (k - 1)) % friends.size();
      friends.erase(friends.begin() + next);
      next = next % friends.size();
      f = next;
    }
    return friends[0] + 1;
  }
};
