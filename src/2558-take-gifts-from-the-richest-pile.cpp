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
    long long tot = 0L, inPile = 0L;
    for (int gift : gifts) {
      tot += gift;
      pq.push(gift);
    }
    while (k--) {
      int top = pq.top();
      pq.pop();
      int rem = (int)sqrt(top);
      inPile += top - rem;
      if (rem > 0) { pq.push(rem); }
    }
    return tot - inPile;
  }
};
