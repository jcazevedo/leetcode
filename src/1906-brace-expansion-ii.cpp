// 1096. Brace Expansion II
// https://leetcode.com/problems/brace-expansion-ii/

#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  set<string> concatenate(const set<string>& left, const set<string>& right) {
    set<string> result;
    for (const string& first : left) {
      for (const string& second : right) { result.insert(first + second); }
    }
    return result;
  }

  set<string> parseUnion(const string& expression, int& i) {
    set<string> result = parseConcatenation(expression, i);
    while (i < (int)expression.size() && expression[i] == ',') {
      ++i;
      set<string> next = parseConcatenation(expression, i);
      result.insert(next.begin(), next.end());
    }
    return result;
  }

  set<string> parseConcatenation(const string& expression, int& i) {
    set<string> result = {""};
    while (i < (int)expression.size() && expression[i] != '}' && expression[i] != ',') {
      set<string> factor;
      if (expression[i] == '{') {
        ++i;
        factor = parseUnion(expression, i);
        ++i;
      } else {
        factor.insert(string(1, expression[i++]));
      }
      result = concatenate(result, factor);
    }
    return result;
  }

 public:
  vector<string> braceExpansionII(string expression) {
    int i = 0;
    set<string> words = parseUnion(expression, i);
    return vector<string>(words.begin(), words.end());
  }
};
