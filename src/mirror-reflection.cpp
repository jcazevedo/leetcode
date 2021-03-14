class Solution {
public:
  int mirrorReflection(int p, int q) {
    int m = 1;
    int n = 1;
    while (m * p != n * q) {
      ++n;
      m = n * q / p;
    }
    if (m % 2 == 0)
      return 0;
    if (n % 2 == 1)
      return 1;
    return 2;
  }
};
