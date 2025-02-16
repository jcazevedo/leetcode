// 1718. Construct the Lexicographically Largest Valid Sequence
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/

#include <vector>

using namespace std;

class Solution {
 private:
  bool go(int i, vector<int>& v, vector<bool>& used, int l, int n) {
    if (i >= l) { return true; }
    for (int j = n; j >= 1; --j) {
      if (used[j]) { continue; }
      if (j != 1 && (i + j >= l || v[i + j] != -1)) { continue; }
      v[i] = j;
      if (j != 1) { v[i + j] = j; }
      used[j] = true;
      int ni = i + 1;
      while (ni < l && v[ni] != -1) { ++ni; }
      if (go(ni, v, used, l, n)) { return true; }
      v[i] = -1;
      if (j != 1) { v[i + j] = -1; }
      used[j] = false;
    }
    return false;
  }

 public:
  vector<int> constructDistancedSequence(int n) {
    int l = (n - 1) * 2 + 1;
    vector<int> ans(l, -1);
    vector<bool> used(n, false);
    go(0, ans, used, l, n);
    return ans;
  }
};
