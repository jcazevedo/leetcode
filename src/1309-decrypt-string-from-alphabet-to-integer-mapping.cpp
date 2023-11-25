// 1309. Decrypt String from Alphabet to Integer Mapping
// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

#include <sstream>
#include <string>

using namespace std;

class Solution {
 private:
  char getChar(string s) {
    if (s.back() == '#') {
      istringstream ss(s.substr(0, s.size() - 1));
      int val;
      ss >> val;
      return val - 1 + 'a';
    }
    return s[0] - '0' - 1 + 'a';
  }

 public:
  string freqAlphabets(string s) {
    string ans = "";
    int i = 0, N = s.size();
    while (i < N) {
      if (i + 2 < N && s[i + 2] == '#') {
        ans += getChar(s.substr(i, 3));
        i += 3;
      } else {
        ans += getChar(s.substr(i, 1));
        i++;
      }
    }
    return ans;
  }
};
