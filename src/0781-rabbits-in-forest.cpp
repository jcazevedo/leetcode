// 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> cnt;
    for (int answer : answers) { ++cnt[answer]; }
    int ans = 0;
    for (const auto& [k, v] : cnt) {
      int tot = v;
      while (tot > k + 1) {
        ans += k + 1;
        tot -= k + 1;
      }
      if (tot) { ans += k + 1; }
    }
    return ans;
  }
};
