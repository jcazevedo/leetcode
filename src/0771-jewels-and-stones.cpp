// 771. Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> jewels;
    for (char ch : J) {
      jewels.insert(ch);
    }
    int cnt = 0;
    for (char ch : S) {
      cnt += jewels.count(ch);
    }
    return cnt;
  }
};
