// 1046. Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (int stone : stones) { pq.push(stone); }
    while (pq.size() > 1) {
      int s1 = pq.top();
      pq.pop();
      int s2 = pq.top();
      pq.pop();
      if (s1 != s2) { pq.push(abs(s1 - s2)); }
    }
    return pq.size() == 0 ? 0 : pq.top();
  }
};
