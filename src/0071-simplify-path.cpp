// 71. Simplify Path
// https://leetcode.com/problems/simplify-path/

#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> s;
    string current = "";
    int N = path.size();
    for (int i = 0; i <= N; ++i) {
      if (i == N || path[i] == '/') {
        if (current == "..") {
          if (!s.empty()) s.pop();
        } else if (!current.empty() && current != ".")
          s.push(current);
        current = "";
      } else
        current += path[i];
    }
    if (s.empty()) return "/";
    string ans = "";
    while (!s.empty()) {
      ans = "/" + s.top() + ans;
      s.pop();
    }
    return ans;
  }
};
