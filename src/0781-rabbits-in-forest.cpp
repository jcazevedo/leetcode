// 781. Rabbits in Forest
// https://leetcode.com/problems/rabbits-in-forest/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> cnt;
    for (int answer : answers) { ++cnt[answer]; }
    int ans = 0;
    for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
      int k = it->first;
      int v = it->second;
      ans += ((v + k) / (k + 1)) * (k + 1);
    }
    return ans;
  }
};
