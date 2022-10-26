#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    map<char, int> ransom_cnt, magazine_cnt;
    for (char ch : ransomNote) ransom_cnt[ch]++;
    for (char ch : magazine) magazine_cnt[ch]++;
    for (auto itr = ransom_cnt.begin(); itr != ransom_cnt.end(); ++itr) {
      if (magazine_cnt[itr->first] < itr->second) return false;
    }
    return true;
  }
};
