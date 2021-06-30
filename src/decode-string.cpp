#include <string>

using namespace std;

class Solution {
private:
  bool is_digit(char ch) { return ch >= '0' && ch <= '9'; }

public:
  string decodeString(string s) {
    string ans = "";
    int N = s.size();
    int i = 0;
    while (i < N) {
      if (is_digit(s[i])) {
        int cnt = s[i] - '0';
        while (i + 1 < N && is_digit(s[i + 1])) {
          cnt *= 10;
          cnt += s[i + 1] - '0';
          ++i;
        }
        int l = i + 1;
        int open = 0;
        int r = l + 1;
        while (r < N) {
          if (s[r] == '[')
            open++;
          if (s[r] == ']') {
            if (open == 0)
              break;
            open--;
          }
          ++r;
        }
        string to_repeat = decodeString(s.substr(l + 1, r - l - 1));
        while (cnt--)
          ans += to_repeat;
        i = r + 1;
      } else {
        ans += s[i++];
      }
    }
    return ans;
  }
};
