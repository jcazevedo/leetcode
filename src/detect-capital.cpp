#include <string>

using namespace std;

class Solution {
private:
  bool all_capitals(const string& word) {
    for (char ch : word)
      if (ch < 'A' || ch > 'Z')
        return false;
    return true;
  }

  bool all_not_capitals(const string& word) {
    for (char ch : word)
      if (ch < 'a' || ch > 'z')
        return false;
    return true;
  }

  bool only_first_capital(const string& word) {
    if (word.empty())
      return false;
    if (word[0] < 'A' || word[0] > 'Z')
      return false;
    for (size_t i = 1; i < word.size(); ++i)
      if (word[i] < 'a' || word[i] > 'z')
        return false;
    return true;
  }

public:
  bool detectCapitalUse(string word) {
    return all_capitals(word) || all_not_capitals(word) ||
           only_first_capital(word);
  }
};
