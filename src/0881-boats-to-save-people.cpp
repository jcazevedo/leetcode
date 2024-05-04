// 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int ans = 0, N = people.size(), i = 0, j = N - 1;
    while (i <= j) {
      if (i == j) {
        ++i;
      } else if (people[i] + people[j] <= limit) {
        ++i;
        --j;
      } else {
        --j;
      }
      ++ans;
    }
    return ans;
  }
};
