// 1503. Last Moment Before All Ants Fall Out of a Plank
// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int ans = 0;
    for (int ant : left) ans = max(ans, ant);
    for (int ant : right) ans = max(ans, n - ant);
    return ans;
  }
};
