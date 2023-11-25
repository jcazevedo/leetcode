// 60. Permutation Sequence
// https://leetcode.com/problems/permutation-sequence/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  int fact(int v) {
    if (v == 0) return 1;
    return v * fact(v - 1);
  }

 public:
  string getPermutation(int n, int k) {
    vector<int> freq(n + 1, 1);
    vector<int> perm(n, -1);
    int cnt = 0, idx = 0;
    while (cnt != k) {
      cnt = 0;
      for (int i = 1; i <= n; ++i) {
        if (freq[i] == 0) continue;
        freq[i]--;
        int xcnt = fact(n - 1 - idx);
        cnt += xcnt;
        if (cnt >= k) {
          perm[idx++] = i;
          k -= (cnt - xcnt);
          break;
        }
        if (cnt < k) freq[i]++;
      }
    }
    for (int i = n; idx < n && i >= 1; --i) {
      if (freq[i]) {
        perm[idx++] = i;
        freq[i++]--;
      }
    }
    string res = "";
    for (int v : perm) res += (v + '0');
    return res;
  }
};
