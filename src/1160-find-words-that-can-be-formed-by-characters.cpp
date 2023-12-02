// 1160. Find Words That Can Be Formed by Characters
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool good(const string& word, map<char, int>& charCount) {
    map<char, int> count;
    for (char ch : word) {
      count[ch]++;
      if (count[ch] > charCount[ch]) { return false; }
    }
    return true;
  }

 public:
  int countCharacters(vector<string>& words, string chars) {
    int ans = 0;
    map<char, int> charCount;
    for (char ch : chars) { charCount[ch]++; }
    for (const string& word : words) {
      if (good(word, charCount)) { ans += word.size(); }
    }
    return ans;
  }
};
