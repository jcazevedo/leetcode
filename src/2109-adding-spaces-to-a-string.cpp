// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string ans = "";
    int j = 0, S = spaces.size(), N = s.size();
    for (int i = 0; i < N; ++i) {
      if (j < S && spaces[j] == i) {
        ans += ' ';
        ++j;
      }
      ans += s[i];
    }
    return ans;
  }
};
