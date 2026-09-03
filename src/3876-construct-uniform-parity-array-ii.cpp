// 3876. Construct Uniform Parity Array II
// https://leetcode.com/problems/construct-uniform-parity-array-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  bool uniformArray(vector<int>& nums1) {
    int minOdd = -1, minEven = -1, oddCount = 0;
    for (int num : nums1) {
      if (num % 2 == 0) {
        if (minEven == -1) {
          minEven = num;
        } else {
          minEven = min(minEven, num);
        }
      } else {
        ++oddCount;
        if (minOdd == -1) {
          minOdd = num;
        } else {
          minOdd = min(minOdd, num);
        }
      }
    }
    return oddCount >= 2 || minOdd < minEven;
  }
};
