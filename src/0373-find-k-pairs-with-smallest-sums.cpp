// 373. Find K Pairs with Smallest Sums
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int N1 = nums1.size(), N2 = nums2.size();
    vector<vector<int>> ans;
    priority_queue<tuple<int, int, int>> pq;
    set<tuple<int, int>> visited;
    pq.push({-(nums1[0] + nums2[0]), 0, 0});
    visited.insert({0, 0});
    int sum, i1, i2;
    while (k-- > 0 && !pq.empty()) {
      tie(sum, i1, i2) = pq.top();
      pq.pop();
      ans.push_back({nums1[i1], nums2[i2]});
      if (i1 + 1 < N1 && visited.find({i1 + 1, i2}) == visited.end()) {
        pq.push({-(nums1[i1 + 1] + nums2[i2]), i1 + 1, i2});
        visited.insert({i1 + 1, i2});
      }
      if (i2 + 1 < N2 && visited.find({i1, i2 + 1}) == visited.end()) {
        pq.push({-(nums1[i1] + nums2[i2 + 1]), i1, i2 + 1});
        visited.insert({i1, i2 + 1});
      }
    }
    return ans;
  }
};
