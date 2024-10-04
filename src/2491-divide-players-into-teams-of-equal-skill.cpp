// 2491. Divide Players Into Teams of Equal Skill
// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    sort(begin(skill), end(skill));
    int N = skill.size();
    int target = skill[0] + skill[N - 1];
    long long ans = skill[0] * skill[N - 1];
    for (int i = 1; i < N / 2; ++i) {
      if (skill[i] + skill[N - i - 1] != target) { return -1; }
      ans += skill[i] * skill[N - i - 1];
    }
    return ans;
  }
};
