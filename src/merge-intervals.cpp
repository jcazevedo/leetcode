#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (const vector<int>& i : intervals) {
      pq.push(make_pair(i[0], i[1]));
    }
    vector<vector<int>> res;
    while (!pq.empty()) {
      pair<int, int> curr = pq.top();
      pq.pop();
      while (!pq.empty() && pq.top().first >= curr.first &&
             pq.top().first <= curr.second) {
        curr.second = max(curr.second, pq.top().second);
        pq.pop();
      }
      res.push_back({curr.first, curr.second});
    }
    return res;
  }
};
