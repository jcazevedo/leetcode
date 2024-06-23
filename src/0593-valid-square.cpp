// 593. Valid Square
// https://leetcode.com/problems/valid-square/

#include <vector>

using namespace std;

class Solution {
 private:
  long long dist_squared(vector<int>& p1, vector<int>& p2) {
    return ((long long)(p1[0] - p2[0])) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
  }

  bool good(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return dist_squared(p1, p2) > 0 && dist_squared(p1, p2) == dist_squared(p2, p3) &&
           dist_squared(p2, p3) == dist_squared(p3, p4) && dist_squared(p3, p4) == dist_squared(p4, p1) &&
           dist_squared(p1, p3) == dist_squared(p2, p4);
  }

 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    return good(p1, p2, p3, p4) || good(p1, p3, p2, p4) || good(p1, p2, p4, p3);
  }
};
