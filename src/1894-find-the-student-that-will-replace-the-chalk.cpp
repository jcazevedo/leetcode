// 1894. Find the Student that Will Replace the Chalk
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include <vector>

using namespace std;

class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    long long tot = 0L;
    for (int c : chalk) { tot += c; }
    k = k % tot;
    int N = chalk.size();
    for (int i = 0; i < N; ++i) {
      if (chalk[i] > k) { return i; }
      k -= chalk[i];
    }
    return -1;
  }
};
