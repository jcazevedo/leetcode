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
      if (expression[i] == 't') {
        arg.push(true);
      } else if (expression[i] == 'f') {
        arg.push(false);
      } else if (expression[i] == '!') {
        op.push('!');
        ++i;
      } else if (expression[i] == '&') {
        op.push('&');
        arg.push(true);
        ++i;
      } else if (expression[i] == '|') {
        op.push('|');
        arg.push(false);
        ++i;
      } else if (expression[i] == ',' || expression[i] == ')') {
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
      }
      ++i;
    }
    return arg.top();
  }
};
