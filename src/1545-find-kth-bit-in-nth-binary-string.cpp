// 1545. Find Kth Bit in Nth Binary String
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
 public:
  char findKthBit(int n, int k, bool flip = false) {
    if (n == 1) { return flip ? '1' : '0'; }
    int midpoint = 1 << (n - 1);
    if (k == midpoint) { return flip ? '0' : '1'; }
    if (k < midpoint) { return findKthBit(n - 1, k, flip); }
    return findKthBit(n - 1, 2 * midpoint - k, flip ^ true);
  }
};
