// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> f;
    for (auto e : nums) f[e]++;

    priority_queue<pair<int, int>> pq;
    for (auto e : f) { pq.push(make_pair(e.second, e.first)); }

    vector<int> res;
    while ((int)res.size() != k) {
      auto curr = pq.top();
      pq.pop();
      res.push_back(curr.second);
    }
    return res;
  }
};
