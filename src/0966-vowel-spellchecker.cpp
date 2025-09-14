// 966. Vowel Spellchecker
// https://leetcode.com/problems/vowel-spellchecker/

#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

  string spellCheck(const string& query, const vector<string>& wordList) {
    string eq = "", cap = "", vow = "";
    int Q = query.size();
    for (const string& word : wordList) {
      int W = word.size();
      if (Q != W) { continue; }
      bool eqb = true, capb = true, vowb = true;
      for (int q = 0; q < Q && (eqb || capb || vowb); ++q) {
        if (query[q] != word[q]) { eqb = false; }
        char qch = tolower(query[q]);
        char wch = tolower(word[q]);
        if (qch != wch) {
          capb = false;
          if (!isVowel(qch) || !isVowel(wch)) { vowb = false; }
        }
      }
      if (eq == "" && eqb) { eq = word; }
      if (cap == "" && capb) { cap = word; }
      if (vow == "" && vowb) { vow = word; }
    }
    if (eq != "") { return eq; }
    if (cap != "") { return cap; }
    if (vow != "") { return vow; }
    return "";
  }

 public:
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    int Q = queries.size();
    vector<string> ans = vector<string>(Q, "");
    for (int q = 0; q < Q; ++q) { ans[q] = spellCheck(queries[q], wordlist); }
    return ans;
  }
};
