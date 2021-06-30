#include <string>
#include <vector>

using namespace std;

class CombinationIterator {
private:
  vector<string> combinations;
  int idx;

  void dfs(const string &characters, int idx, int curr, int n_set, int cnt) {
    if (idx == characters.size()) {
      if (n_set == cnt) {
        string ans = "";
        for (size_t i = 0; i < characters.size(); ++i) {
          if (curr & (1 << i))
            ans += characters[characters.size() - i - 1];
        }
        reverse(ans.begin(), ans.end());
        combinations.push_back(ans);
      }
      return;
    }
    if (n_set < cnt)
      dfs(characters, idx + 1, (curr << 1) + 1, n_set + 1, cnt);
    dfs(characters, idx + 1, curr << 1, n_set, cnt);
  }

public:
  CombinationIterator(string characters, int combinationLength) {
    dfs(characters, 0, 0, 0, combinationLength);
    idx = 0;
  }

  string next() { return combinations[idx++]; }

  bool hasNext() { return idx < combinations.size(); }
};
