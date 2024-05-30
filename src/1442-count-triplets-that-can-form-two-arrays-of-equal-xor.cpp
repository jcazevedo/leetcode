// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

#include <vector>

using namespace std;

class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int N = arr.size();

    vector<int> prefixXor(N);
    prefixXor[0] = arr[0];
    for (int i = 1; i < N; ++i) prefixXor[i] = prefixXor[i - 1] ^ arr[i];

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int a = prefixXor[j - 1];
        if (i - 1 >= 0) a ^= prefixXor[i - 1];
        for (int k = j; k < N; ++k) {
          int b = prefixXor[k] ^ prefixXor[j - 1];
          if (a == b) ++ans;
        }
      }
    }

    return ans;
  }
};
