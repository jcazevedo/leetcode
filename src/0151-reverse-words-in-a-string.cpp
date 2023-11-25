// 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    stack<string> st;
    istringstream ss(s);
    string tmp;
    while (ss >> tmp) { st.push(tmp); }
    string res = "";
    while (!st.empty()) {
      if (!res.empty()) res += " ";
      res += st.top();
      st.pop();
    }
    return res;
  }
};
