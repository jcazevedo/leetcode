#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> m;
    int N = strs.size();
    for (int i = 0; i < N; i++) {
      string s = strs[i];
      sort(s.begin(), s.end());
      m[s].push_back(strs[i]);
    }
    vector<vector<string>> res;
    for (auto itr = m.begin(); itr != m.end(); itr++)
      res.push_back(itr->second);
    return res;
  }
};
