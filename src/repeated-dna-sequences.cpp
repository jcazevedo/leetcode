#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if (s.size() < 10) return ans;
    set<string> visited;
    set<string> repeated;
    string curr;
    for (int i = 0; i < 10; ++i) curr += s[i];
    visited.insert(curr);
    int N = s.size();
    for (int i = 10; i < N; ++i) {
      curr = curr.substr(1);
      curr += s[i];
      if (visited.find(curr) != visited.end()) repeated.insert(curr);
      visited.insert(curr);
    }
    for (const string& s : repeated) ans.push_back(s);
    return ans;
  }
};
