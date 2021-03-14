#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> strings;

  void gen(int n, string curr = "") {
    if (curr.size() == n) {
      strings.push_back(curr);
      return;
    }

    for (char c = 'a'; c <= 'c'; ++c) {
      if (!curr.empty() && c == curr.back())
        continue;

      gen(n, curr + c);
    }
  }

public:
  string getHappyString(int n, int k) {
    strings.clear();
    gen(n);
    sort(strings.begin(), strings.end());
    if (k > strings.size())
      return "";
    return strings[k - 1];
  }
};
