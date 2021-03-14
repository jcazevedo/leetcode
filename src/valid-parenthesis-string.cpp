#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    stack<int> opens, wildcards;
    int N = s.size();
    for (int i = 0; i < N; ++i) {
      if (s[i] == '*')
        wildcards.push(i);
      if (s[i] == ')') {
        if (!opens.empty())
          opens.pop();
        else if (!wildcards.empty())
          wildcards.pop();
        else
          return false;
      }
      if (s[i] == '(')
        opens.push(i);
    }
    while (!opens.empty()) {
      if (wildcards.empty() || wildcards.top() < opens.top())
        return false;
      wildcards.pop();
      opens.pop();
    }
    return true;
  }
};
