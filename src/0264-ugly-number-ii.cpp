// 264. Ugly Number II
// https://leetcode.com/problems/ugly-number-ii/

#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
 public:
  int nthUglyNumber(int n) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    unordered_set<ll> visited;
    pq.push(1);
    visited.insert(1);
    while (n > 1) {
      ll curr = pq.top();
      pq.pop();
      ll n2 = curr * 2;
      ll n3 = curr * 3;
      ll n5 = curr * 5;
      if (visited.find(n2) == visited.end()) {
        pq.push(n2);
        visited.insert(n2);
      }
      if (visited.find(n3) == visited.end()) {
        pq.push(n3);
        visited.insert(n3);
      }
      if (visited.find(n5) == visited.end()) {
        pq.push(n5);
        visited.insert(n5);
      }
      n--;
    }
    return pq.top();
  }
};
