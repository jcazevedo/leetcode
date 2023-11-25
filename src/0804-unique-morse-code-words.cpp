// 804. Unique Morse Code Words
// https://leetcode.com/problems/unique-morse-code-words/

#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  static string translation[];

  string translate(const string& word) {
    string ans = "";
    for (const char& ch : word) ans += translation[ch - 'a'];
    return ans;
  }

 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    set<string> translations;
    for (const string& word : words) translations.insert(translate(word));
    return translations.size();
  }
};

string Solution::translation[] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
