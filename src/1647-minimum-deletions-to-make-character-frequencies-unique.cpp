// 1647. Minimum Deletions to Make Character Frequencies Unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minDeletions(string s) {
    int N = s.size();
    unordered_map<char, int> cnts;
    for (int i = 0; i < N; ++i)
      cnts[s[i]]++;
    map<int, set<char>> reverseCnts;
    for (auto it = cnts.begin(); it != cnts.end(); ++it)
      reverseCnts[it->second].insert(it->first);
    int ans = 0;
    for (auto it = reverseCnts.rbegin(); it != reverseCnts.rend(); ++it) {
      while (reverseCnts[it->first].size() > 1) {
        char ch = *reverseCnts[it->first].begin();
        for (int targetCnt = it->first - 1; targetCnt >= 0; --targetCnt) {
          if (targetCnt == 0 || reverseCnts.find(targetCnt) == reverseCnts.end()) {
            ans += (it->first - targetCnt);
            reverseCnts[it->first].erase(ch);
            if (targetCnt != 0)
              reverseCnts[targetCnt].insert(ch);
            break;
          }
        }
      }
    }
    return ans;
  }
};
