// 17. Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  map<char, string> m = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  vector<string> aux(string digits) {
    vector<string> res;
    if (digits.empty()) {
      res.push_back("");
      return res;
    }
    vector<string> other = aux(digits.substr(1));
    string t = m[digits[0]];
    for (int i = 0; i < (int)t.size(); i++) {
      for (int j = 0; j < (int)other.size(); j++) { res.push_back(t[i] + other[j]); }
    }
    return res;
  }

 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    return aux(digits);
  }
};
