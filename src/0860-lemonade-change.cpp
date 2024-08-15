// 860. Lemonade Change
// https://leetcode.com/problems/lemonade-change/

#include <vector>

using namespace std;

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    vector<int> cnt(20 + 1, 0);
    for (const int& bill : bills) {
      if (bill == 5) {
        ++cnt[5];
      } else if (bill == 10) {
        if (cnt[5] == 0) { return false; }
        --cnt[5];
        ++cnt[10];
      } else if (bill == 20) {
        if (cnt[10] >= 1 && cnt[5] >= 1) {
          --cnt[10];
          --cnt[5];
        } else if (cnt[5] >= 3) {
          cnt[5] -= 3;
        } else {
          return false;
        }
        ++cnt[20];
      }
    }
    return true;
  }
};
