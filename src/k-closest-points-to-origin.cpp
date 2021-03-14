#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<long long, vector<int>>, vector<pair<long long, vector<int>>>, greater<pair<long long, vector<int>>>> pq;
    vector<vector<int>> res;
    for (vector<int> point : points) {
      long long dist = point[0] * point[0] + point[1] * point[1];
      pq.emplace(dist, point);
    }
    while (!pq.empty() && res.size() < K) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }
};
