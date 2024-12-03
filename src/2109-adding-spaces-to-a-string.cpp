// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string addSpaces(string s, vector<int>& spaces) {
    string ans = "";
    int i = 0, j = 0, S = spaces.size(), N = s.size();
    while (i < N) {
      if (j < S && spaces[j] == i) {
        ans += ' ';
        ++j;
      }
      ans += s[i++];
    }
    return ans;
  }
};
