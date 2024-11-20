// 2683. Neighboring Bitwise XOR
// https://leetcode.com/problems/neighboring-bitwise-xor/

#include <vector>

using namespace std;

class Solution {
 public:
  bool doesValidArrayExist(vector<int>& derived) {
    int N = derived.size();
    if (N == 1) { return derived[0] == 0; }
    int remXor = 0;
    for (int i = 0; i < N; ++i) { remXor ^= derived[i]; }
    int leftXor = 0;
    for (int i = 0; i < N - 1; ++i) {
      remXor ^= derived[i];
      leftXor ^= derived[i];
      if ((remXor ^ leftXor) != 0) { return false; }
    }
    return true;
  }
};
