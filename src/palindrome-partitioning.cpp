#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, vector<vector<string>>> cache;
  string _s;

  bool is_palindrome(const string& s) {
    int N = s.size();
    for (int i = 0; i < N / 2; ++i) {
      if (s[i] != s[N - i - 1]) { return false; }
    }
    return true;
  }

  vector<vector<string>> go(int idx) {
    if (idx >= _s.size()) { return {}; }
    if (cache.count(idx) == 0) {
      vector<vector<string>> ans;
      for (size_t j = idx; j < _s.size(); ++j) {
        string target = _s.substr(idx, j - idx + 1);
        if (is_palindrome(target)) {
          if (j + 1 >= _s.size()) {
            ans.push_back({target});
          } else {
            vector<vector<string>> next = go(j + 1);
            for (vector<string> opt : next) {
              vector<string> curr = {target};
              for (string s : opt) { curr.push_back(s); }
              ans.push_back(curr);
            }
          }
        }
      }
      cache[idx] = ans;
    }
    return cache[idx];
  }

public:
  vector<vector<string>> partition(string s) {
    cache.clear();
    _s = s;
    return go(0);
  }
};
