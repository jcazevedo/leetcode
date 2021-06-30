#include <string>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int NS = S.size(), NT = T.size(), si = NS - 1, ti = NT - 1, del = 0;
    while (si >= 0 || ti >= 0) {
      del = 0;
      while (si >= 0 && (S[si] == '#' || del > 0)) {
        if (S[si] == '#') {
          del++;
        }
        if (S[si] != '#') {
          del--;
        }
        si--;
      }
      del = 0;
      while (ti >= 0 && (T[ti] == '#' || del > 0)) {
        if (T[ti] == '#') {
          del++;
        }
        if (T[ti] != '#') {
          del--;
        }
        ti--;
      }
      if (ti >= 0 && si >= 0 && T[ti] != S[si])
        return false;
      if (ti < 0 && si >= 0)
        return false;
      if (si < 0 && ti >= 0)
        return false;
      si--;
      ti--;
    }
    return true;
  }
};
