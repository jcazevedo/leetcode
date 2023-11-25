// 986. Interval List Intersections
// https://leetcode.com/problems/interval-list-intersections/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A,
                                           vector<vector<int>>& B) {
    vector<vector<int>> intersection;
    int a = 0, b = 0;
    while (a < (int)A.size() && b < (int)B.size()) {
      int left = max(A[a][0], B[b][0]);
      int right = min(A[a][1], B[b][1]);
      if (left <= right) intersection.push_back({left, right});
      if (A[a][1] < B[b][1])
        a++;
      else
        b++;
    }
    return intersection;
  }
};
