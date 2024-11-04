// 3163. String Compression III
// https://leetcode.com/problems/string-compression-iii/

#include <string>

using namespace std;

class Solution {
 public:
  string compressedString(string word) {
    string ans = "";
    int cnt = 1;
    int N = word.size();
    for (int i = 1; i < N; ++i) {
      if (word[i] == word[i - 1]) {
        if (cnt == 9) {
          ans += (cnt + '0');
          ans += word[i];
          cnt = 1;
        } else {
          ++cnt;
        }
      } else {
        ans += (cnt + '0');
        ans += word[i - 1];
        cnt = 1;
      }
    }
    ans += (cnt + '0');
    ans += word[N - 1];
    return ans;
  }
};
