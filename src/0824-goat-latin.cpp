// 824. Goat Latin
// https://leetcode.com/problems/goat-latin/

#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> getWords(string sentence) {
    vector<string> ans;
    string currentWord = "";
    for (const char& ch : sentence) {
      if (ch != ' ')
        currentWord += ch;
      else {
        ans.push_back(currentWord);
        currentWord = "";
      }
    }
    if (!currentWord.empty())
      ans.push_back(currentWord);
    return ans;
  }

  string transform(string word, int index) {
    char firstChar = tolower(word[0]);
    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' ||
        firstChar == 'o' || firstChar == 'u')
      word += "ma";
    else
      word = word.substr(1) + word[0] + "ma";
    for (int i = 0; i < index; ++i)
      word += 'a';
    return word;
  }

public:
  string toGoatLatin(string sentence) {
    vector<string> words = getWords(sentence);
    string ans = "";
    for (int i = 0; i < (int)words.size(); ++i) {
      ans += transform(words[i], i + 1);
      if (i + 1 < (int)words.size())
        ans += ' ';
    }
    return ans;
  }
};
