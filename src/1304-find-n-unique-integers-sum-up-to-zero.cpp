// 1304. Find N Unique Integers Sum up to Zero
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> arr(n, 0);
    if (n % 2 == 0) {
      for (int i = 0; i < n; ++i) {
        arr[i] = (i + 2) / 2;
        if ((i + 2) % 2 == 0) { arr[i] = -arr[i]; }
      }
    } else {
      for (int i = 1; i < n; ++i) {
        arr[i] = (i + 1) / 2;
        if ((i + 1) % 2 == 0) { arr[i] = -arr[i]; }
      }
    }
    return arr;
  }
};
