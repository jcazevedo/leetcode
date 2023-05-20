#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> cnt;
    for (char ch : s)
      cnt[ch]++;
    vector<pair<int, char>> lst;
    for (pair<char, int> pp : cnt)
      lst.emplace_back(pp.second, pp.first);
    sort(lst.begin(), lst.end());
    reverse(lst.begin(), lst.end());
    string res = "";
    for (pair<int, char> pp : lst)
      res += string(pp.first, pp.second);
    return res;
  }
};
