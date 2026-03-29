// 1534. Count Good Triplets
// https://leetcode.com/problems/count-good-triplets/

#include <cmath>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (abs(arr[j] - arr[i]) > a) { continue; }
        for (int k = j + 1; k < n; ++k) {
          if (abs(arr[j] - arr[k]) > b) { continue; }
          if (abs(arr[i] - arr[k]) > c) { continue; }
          ++ans;
        }
      }
    }
    return ans;
  }
};
