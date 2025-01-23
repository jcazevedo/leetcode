// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  int toInt(string s) {
    int ans;
    istringstream ss(s);
    ss >> ans;
    return ans;
  }

 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> operands;
    for (const string& s : tokens) {
      if (s == "+") {
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();
        operands.push(v1 + v2);
      } else if (s == "-") {
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();
        operands.push(v1 - v2);
      } else if (s == "*") {
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();
        operands.push(v1 * v2);
      } else if (s == "/") {
        int v2 = operands.top();
        operands.pop();
        int v1 = operands.top();
        operands.pop();
        operands.push(v1 / v2);
      } else {
        operands.push(toInt(s));
      }
    }
    return operands.top();
  }
};
