#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    int L = num.size();
    vector<bool> used(L, true);
    int left = 0;
    while (k > 0 && left < L) {
      while (left < L && (num[left] == '0' || !used[left])) {
        used[left] = false;
        left++;
      }
      int best = left;
      for (int i = best + 1; i < L && num[i] >= num[best]; ++i) {
        if (!used[i]) continue;
        best = i;
      }
      used[best] = false;
      k--;
    }
    while (left < L && (num[left] == '0' || !used[left])) {
      used[left] = false;
      left++;
    }
    string res = "";
    for (int i = 0; i < L; ++i) {
      if (used[i]) res += num[i];
    }
    if (res == "") res = "0";
    return res;
  }
};
