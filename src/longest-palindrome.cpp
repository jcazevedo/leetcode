#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> cnt;
    for (char ch : s)
      cnt[ch]++;
    int ans = 0;
    bool used_one = false;
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      ans += (itr->second / 2) * 2;
      if (itr->second % 2 != 0 && !used_one) {
        ans++;
        used_one = true;
      }
    }
    return ans;
  }
};
