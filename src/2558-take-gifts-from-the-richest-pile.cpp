// 2558. Take Gifts From the Richest Pile
// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> pq;
    long long ans = 0L;
    for (int gift : gifts) {
      ans += gift;
      pq.push(gift);
    }
    while (k--) {
      int top = pq.top();
      pq.pop();
      int rem = (int)sqrt(top);
      ans -= top - rem;
      if (rem > 0) { pq.push(rem); }
    }
    return ans;
  }
};
