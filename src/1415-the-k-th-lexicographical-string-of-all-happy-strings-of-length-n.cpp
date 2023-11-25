// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> strings;

  void gen(int n, string curr = "") {
    if ((int)curr.size() == n) {
      strings.push_back(curr);
      return;
    }

    for (char c = 'a'; c <= 'c'; ++c) {
      if (!curr.empty() && c == curr.back()) continue;

      gen(n, curr + c);
    }
  }

 public:
  string getHappyString(int n, int k) {
    strings.clear();
    gen(n);
    sort(strings.begin(), strings.end());
    if (k > (int)strings.size()) return "";
    return strings[k - 1];
  }
};
