// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    int N = s.size();
    for (int i = 0; i < N / 2; ++i)
      swap(s[i], s[N - i - 1]);
  }
};
