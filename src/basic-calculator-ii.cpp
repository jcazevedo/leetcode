#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
  int string_to_int(string s) {
    istringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
  }

public:
  int calculate(string s) {
    stack<int> nums;
    string curr = "";
    char op = '+';
    string trimmed = "";
    for (char ch : s) {
      if (ch != ' ')
        trimmed += ch;
    }
    int N = trimmed.size();
    for (int i = 0; i < N; ++i) {
      if (trimmed[i] != ' ') {
        if (isdigit(trimmed[i]))
          curr += trimmed[i];
        if (!isdigit(trimmed[i]) || i + 1 == N) {
          if (op == '+')
            nums.push(string_to_int(curr));
          else if (op == '-')
            nums.push(-string_to_int(curr));
          else if (op == '*') {
            int n = nums.top();
            nums.pop();
            nums.push(n * string_to_int(curr));
          } else if (op == '/') {
            int n = nums.top();
            nums.pop();
            nums.push(n / string_to_int(curr));
          }
          curr = "";
          op = trimmed[i];
        }
      }
    }
    int ans = 0;
    while (!nums.empty()) {
      ans += nums.top();
      nums.pop();
    }
    return ans;
  }
};
