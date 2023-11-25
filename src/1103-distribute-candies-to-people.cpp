// 1103. Distribute Candies to People
// https://leetcode.com/problems/distribute-candies-to-people/

#include <vector>

using namespace std;

class Solution {
public:
  /**
   * Example for num_people = 4
   *
   * 1  2  3  4 = 10
   * 5  6  7  8 = 26 (4 * 4 + 1 + 2 + 3 + 4)
   * 9 10 11 12 = 42 (4 * (4 + 4) + 1 + 2 + 3 + 4)
   */
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people, 0);
    int round = 0;
    while ((round * num_people) * num_people +
               (num_people * (num_people + 1)) / 2 <
           candies) {
      candies -= ((round * num_people) * num_people +
                  (num_people * (num_people + 1)) / 2);
      round++;
    }
    for (int i = 0; i < num_people; ++i) {
      int to_give = min(candies, (round * num_people + i + 1));
      candies -= to_give;
      ans[i] += to_give;
      ans[i] += round * (i + 1);
      int comp_round = max(round - 1, 0);
      ans[i] += ((comp_round * (comp_round + 1)) / 2) * num_people;
    }
    return ans;
  }
};
