// 1791. Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/

#include <vector>

using namespace std;

class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    if (edges[1][0] == edges[0][0] || edges[1][0] == edges[0][1]) { return edges[1][0]; }
    return edges[1][1];
  }
};
