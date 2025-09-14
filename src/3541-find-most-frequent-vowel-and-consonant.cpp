// 3541. Find Most Frequent Vowel and Consonant
// https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/

#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

 public:
  int maxFreqSum(string s) {
    unordered_map<char, int> freq;
    for (char ch : s) { ++freq[ch]; }
    int vCnt = 0, cCnt = 0;
    for (unordered_map<char, int>::iterator itr = freq.begin(); itr != freq.end(); ++itr) {
      if (isVowel(itr->first)) {
        vCnt = max(vCnt, itr->second);
      } else {
        cCnt = max(cCnt, itr->second);
      }
    }
    return vCnt + cCnt;
  }
};
