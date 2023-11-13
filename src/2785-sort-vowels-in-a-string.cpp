// 2785. Sort Vowels in a String
// https://leetcode.com/problems/sort-vowels-in-a-string/

#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

class Solution {
private:
  bool isVowel(char ch) {
    char lch = tolower(ch);
    return lch == 'a' || lch == 'e' || lch == 'i' || lch == 'o' || lch == 'u';
  }

public:
  string sortVowels(string s) {
    int N = s.size();

    string vowels = "";
    for (int i = 0; i < N; ++i)
      if (isVowel(s[i]))
        vowels += s[i];

    sort(vowels.begin(), vowels.end());

    int v = 0;
    for (int i = 0; i < N; ++i)
      if (isVowel(s[i]))
        s[i] = vowels[v++];

    return s;
  }
};
