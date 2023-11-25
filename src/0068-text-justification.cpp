// 68. Text Justification
// https://leetcode.com/problems/text-justification/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  string build_line(const vector<string>& words, int maxWidth) {
    if (words.size() == 1)
      return words[0] + string(maxWidth - words[0].size(), ' ');
    int len = 0;
    for (string word : words) len += word.size();
    int spaces = words.size() - 1;
    int rem = maxWidth - (len + spaces);
    int to_fill = spaces + rem;
    int divs = to_fill / (words.size() - 1);
    int rem_divs = to_fill - (divs * (words.size() - 1));
    string res = "";
    for (string word : words) {
      if (res != "") {
        res += string(divs, ' ');
        if (rem_divs > 0) {
          res += " ";
          rem_divs--;
        }
      }
      res += word;
    }
    return res;
  }

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n_words = words.size();
    vector<string> line;
    int line_width = 0;
    for (int w = 0; w < n_words; ++w) {
      int next_width = (line.size() != 0 ? 1 : 0) + words[w].size();
      if (next_width + line_width > maxWidth) {
        result.push_back(build_line(line, maxWidth));
        line.clear();
        line_width = 0;
      }
      next_width = (line.size() != 0 ? 1 : 0) + words[w].size();
      line.push_back(words[w]);
      line_width += next_width;
    }
    if (line.size() != 0) {
      string res = "";
      for (string word : line) {
        if (res != "") res += " ";
        res += word;
      }
      int rem = maxWidth - res.size();
      if (rem > 0) res += string(rem, ' ');
      result.push_back(res);
    }
    return result;
  }
};
