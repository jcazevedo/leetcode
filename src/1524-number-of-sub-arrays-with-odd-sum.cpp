// 1524. Number of Sub-arrays With Odd Sum
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int numOfSubarrays(vector<int>& arr) {
    int N = arr.size(), currOdd = 0, currEven = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
      int nextOdd, nextEven;
      if (arr[i] % 2 == 0) {
        nextEven = (1 + currEven) % MOD;
        nextOdd = currOdd;
      } else {
        nextOdd = (1 + currEven) % MOD;
        nextEven = currOdd;
      }
      currOdd = nextOdd;
      currEven = nextEven;
      ans = (ans + currOdd) % MOD;
    }
    return ans;
  }
};
