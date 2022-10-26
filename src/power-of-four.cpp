#include <cmath>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int num) {
    if (num <= 0) return false;
    double logNum = log(num);
    double log4 = log(4);
    int power = logNum / log4;
    if (num == pow(4, power)) return true;
    return false;
  }
};
