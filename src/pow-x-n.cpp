class Solution {
 private:
  double aux(double x, long long n) {
    double res = 1.0;
    while (n > 0) {
      if (n & 1) res = (res * x);
      n >>= 1;
      x = x * x;
    }
    return res;
  }

 public:
  double myPow(double x, int n) {
    if (x == 0.0) return 0.0;
    if (n < 0) return 1.0 / aux(x, -((long long)n));
    return aux(x, n);
  }
};
