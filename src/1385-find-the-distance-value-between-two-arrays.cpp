// 1385. Find the Distance Value Between Two Arrays
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;
    for (int n1 : arr1) {
      bool good = true;
      for (int n2 : arr2) {
        if (abs(n1 - n2) <= d) {
          good = false;
          break;
        }
      }
      if (good) { ++ans; }
    }
    return ans;
  }
};
