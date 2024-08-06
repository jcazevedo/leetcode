// 3016. Minimum Number of Pushes to Type Word II
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

#include <algorithm>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumPushes(string word) {
    unordered_map<char, int> cnt;
    for (const char& ch : word) { ++cnt[ch]; }
    vector<tuple<int, char>> v;
    for (unordered_map<char, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr) {
      v.emplace_back(itr->second, itr->first);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    int N = v.size();
    for (int i = 0; i < N; ++i) { ans += get<0>(v[i]) * (i / 8 + 1); }
    return ans;
  }
};
