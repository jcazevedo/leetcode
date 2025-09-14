// 3227. Vowels Game in a String
// https://leetcode.com/problems/vowels-game-in-a-string/

#include <string>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

 public:
  bool doesAliceWin(string s) {
    int cnt = 0;
    for (char ch : s) {
      if (isVowel(ch)) { ++cnt; }
    }
    return cnt > 0;
  }
};
