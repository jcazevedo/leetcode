// 3403. Find the Lexicographically Largest String From the Box I
// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1) { return word; }
    string ans = "";
    int n = word.size();
    int l = n - (numFriends - 1);
    for (int i = 0; i < n; ++i) { ans = max(ans, word.substr(i, min(l, n - i))); }
    return ans;
  }
};
