#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  void gen(int o, int c, int n, string current, vector<string>& res) {
    if (current.size() >= n * 2) {
      res.push_back(current);
      return;
    }
    if (o > c)
      gen(o, c + 1, n, current + ")", res);
    if (o < n)
      gen(o + 1, c, n, current + "(", res);
  }

public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    gen(0, 0, n, "", res);
    return res;
  }
};
