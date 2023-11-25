// 1295. Find Numbers with Even Number of Digits
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

#include <vector>

using namespace std;

class Solution {
 private:
  int n_digits(int n) {
    int cnt = 0;
    while (n) {
      cnt++;
      n /= 10;
    }
    return cnt;
  }

 public:
  int findNumbers(vector<int>& nums) {
    int cnt = 0;
    for (int v : nums) {
      if (n_digits(v) % 2 == 0) cnt++;
    }
    return cnt;
  }
};
