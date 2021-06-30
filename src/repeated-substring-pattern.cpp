#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool kmp(const string &W, const string &S) {
    int M = W.size(), N = S.size();
    vector<int> T(M, 0);
    int len = 0;
    T[0] = 0;
    int i = 1;
    while (i < M) {
      if (W[i] == W[len]) {
        len++;
        T[i] = len;
        i++;
      } else if (len != 0) {
        len = T[len - 1];
      } else {
        T[i] = 0;
        i++;
      }
    }
    int j;
    i = j = 0;
    while (i < N) {
      if (W[j] == S[i]) {
        j++;
        i++;
      }
      if (j == M)
        return true;
      if (W[j] != S[i]) {
        if (j != 0)
          j = T[j - 1];
        else
          i = i + 1;
      }
    }
    return false;
  }

public:
  bool repeatedSubstringPattern(string s) {
    string res = (s + s).substr(1, s.size() * 2 - 2);
    return kmp(s, res);
  }
};
