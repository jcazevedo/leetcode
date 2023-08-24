// 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/

#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> cnt;
    for (const char& ch : s)
      cnt[ch]++;

    priority_queue<pair<int, char>> pq;
    for (char ch = 'a'; ch <= 'z'; ++ch)
      if (cnt[ch] > 0)
        pq.push(make_pair(cnt[ch], ch));

    string ans = "";
    while (!pq.empty()) {
      pair<int, char> curr = pq.top();
      pq.pop();
      ans += curr.second;

      if (pq.empty()) {
        if (curr.first > 1)
          return "";
        break;
      }

      pair<int, char> next = pq.top();
      pq.pop();
      ans += next.second;
      if (curr.first - 1 > 0)
        pq.push(make_pair(curr.first - 1, curr.second));
      if (next.first - 1 > 0)
        pq.push(make_pair(next.first - 1, next.second));
    }
    return ans;
  }
};
