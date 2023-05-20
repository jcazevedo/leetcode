class Solution {
private:
  long long reverse(int x) {
    long long res = 0;
    while (x) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return res;
  }

public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    return x == reverse(x);
  }
};
