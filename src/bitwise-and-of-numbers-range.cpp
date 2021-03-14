class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int bit = 0, res = 0;
    while (m && n) {
      if (m == n)
        res += ((m & 1) << bit);
      bit++;
      m /= 2;
      n /= 2;
    }
    return res;
  }
};
