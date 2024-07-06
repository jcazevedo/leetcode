// 2582. Pass the Pillow
// https://leetcode.com/problems/pass-the-pillow/

class Solution {
 public:
  int passThePillow(int n, int time) {
    int rem = time % (n - 1), loops = time / (n - 1);
    if (loops % 2 == 0) return 1 + rem;
    return n - rem;
  }
};
