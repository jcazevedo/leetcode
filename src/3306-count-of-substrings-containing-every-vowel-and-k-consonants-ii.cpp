// 3306. Count of Substrings Containing Every Vowel and K Consonants II
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  bool isVowel(char ch) { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; }

 public:
  long long countOfSubstrings(string word, int k) {
    int n = word.size();
    vector<int> nc(n);
    int nci = n;
    for (int i = n - 1; i >= 0; --i) {
      nc[i] = nci;
      if (!isVowel(word[i])) { nci = i; }
    }
    long long ans = 0;
    int c = 0, vs = 0, s = 0, e = 0;
    unordered_map<char, int> v;
    while (e < n) {
      char newCh = word[e];
      if (isVowel(newCh)) {
        if (v[newCh] == 0) { ++vs; }
        ++v[newCh];
      } else {
        ++c;
      }
      while (c > k) {
        char startCh = word[s];
        if (isVowel(startCh)) {
          --v[startCh];
          if (v[startCh] == 0) { --vs; }
        } else {
          --c;
        }
        ++s;
      }
      while (s < n && vs == 5 && c == k) {
        ans += nc[e] - e;
        char startCh = word[s];
        if (isVowel(startCh)) {
          --v[startCh];
          if (v[startCh] == 0) { --vs; }
        } else {
          --c;
        }
        ++s;
      }
      ++e;
    }
    return ans;
  }
};
