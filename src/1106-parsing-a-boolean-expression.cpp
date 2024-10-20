// 1106. Parsing A Boolean Expression
// https://leetcode.com/problems/parsing-a-boolean-expression/

#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool parseBoolExpr(string expression) {
    stack<char> op;
    stack<bool> arg;
    int N = expression.size();
    int i = 0;
    while (i < N) {
      switch (expression[i]) {
        case 't':
          arg.push(true);
          break;
        case 'f':
          arg.push(false);
          break;
        case '!':
          op.push('!');
          ++i;
          break;
        case '&':
          op.push('&');
          arg.push(true);
          ++i;
          break;
        case '|':
          op.push('|');
          arg.push(false);
          ++i;
          break;
        case ',':
        case ')':
          bool arg1 = arg.top();
          arg.pop();
          if (op.top() == '!') {
            arg.push(!arg1);
          } else {
            bool arg2 = arg.top();
            arg.pop();
            if (op.top() == '&') {
              arg.push(arg1 && arg2);
            } else if (op.top() == '|') {
              arg.push(arg1 || arg2);
            }
          }
          if (expression[i] == ')') { op.pop(); }
          break;
      }
      ++i;
    }
    return arg.top();
  }
};
